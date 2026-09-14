//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Thu Feb 29 13:30:55 IST 2024
// User: KRAMESH5
// System: GIP
// Configuration: Platform_Recovery
// Project: EU_BMW_MIC
// Message Catalogue version : 1.0.3
//
//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "FlashHandler.hpp"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT(BlAppGpLogContext);

int32_t FlashHandler::programCompEmmcPartition(std::string partition, std::string file)
{
    int32_t sts = -1;
    int32_t ret = -1;
    std::string cmd;

    cmd = "/bin/tar -xzOf " + file + " | dd of=" + partition;

    //printf("command is %s \n",cmd.c_str());

    ret = system (cmd.c_str());

    if (WIFEXITED(ret) && !WEXITSTATUS(ret))
    {
        sts = 0;
        LOGI(&BlAppGpLogContext, "Flashing success");
    }
    else
    {
        LOGE(&BlAppGpLogContext, "Flashing failed");
        return sts;
    }
    return sts;
}

int32_t FlashHandler::programEmmcPartition(std::string partition, std::string file)
{
    int32_t sts = -1;
    int32_t ret = -1;
    std::string cmd;

    LOGI(&BlAppGpLogContext, "Flashing ", file, " -> ", partition);

    if(partition == "/dev/mmcblk0boot0")
    {
        cmd = "echo 0 > /sys/block/mmcblk0boot0/force_ro";

         ret = system (cmd.c_str());

        if (WIFEXITED(ret) && !WEXITSTATUS(ret))
        {
            sts = 0;
            LOGI(&BlAppGpLogContext, "Flashing success");
        }
        else
        {
            LOGE(&BlAppGpLogContext, "Flashing failed");
            return sts;
        }

    }

    if(partition == "/dev/mmcblk0boot1")
    {
        cmd = "echo 0 > /sys/block/mmcblk0boot1/force_ro";

         ret = system (cmd.c_str());

        if (WIFEXITED(ret) && !WEXITSTATUS(ret))
        {
            sts = 0;
            LOGI(&BlAppGpLogContext, "Flashing success");
        }
        else
        {
            LOGE(&BlAppGpLogContext, "Flashing failed");
            return sts;
        }

    }

    sts = -1;
    cmd = "dd if=" + file + " of=" + partition;
    ret = system (cmd.c_str());

    if (WIFEXITED(ret) && !WEXITSTATUS(ret))
    {
        sts = 0;
        LOGI(&BlAppGpLogContext, "Flashing success");
    }
    else
    {
        LOGE(&BlAppGpLogContext, "Flashing failed");
    }

    return sts;
}


int32_t FlashHandler::programNORPartition(std::string partition, std::string file)
{
    int32_t sts = -1, ret = 0;
    const size_t CHUNK_SIZE = 512 * 1024; // 512KB
    int SrcPart = -1;
    char* bufferData = new char[CHUNK_SIZE];
    size_t totalBytes = 0;
    size_t bytesRead;
    off_t offset = 0;
	struct stat fileStat;
    struct erase_info_user erase;

    LOGI(&BlAppGpLogContext, "Flashing ", file, " -> ", partition);

    if (stat(file.c_str(), &fileStat) != 0)
	{
        LOGE(&BlAppGpLogContext, "Input file not found: ", file);
        return sts;
    }

	SrcPart = open(file.c_str(), O_RDONLY | O_SYNC);

	if (SrcPart < 0)
	{
		LOGE(&BlAppGpLogContext, "Failed to open input file: ", file);
		return sts;
    }

    int partitionFd = open(partition.c_str(), O_SYNC | O_RDWR);
    if (partitionFd < 0) {
        LOGE(&BlAppGpLogContext, "Failed to open NOR partition: ", partition);
        ret = -1;
        goto err;
    }

    struct mtd_info_user mtdInfo;
    if (ioctl(partitionFd, MEMGETINFO, &mtdInfo) != 0) {
        LOGE(&BlAppGpLogContext, "Failed to get MTD info");
        ret = -1;
        goto err;
    }

    LOGI(&BlAppGpLogContext, "MTD Info - size: ", mtdInfo.size, " erase size: ", mtdInfo.erasesize, " write size: ", mtdInfo.writesize);

    LOGI(&BlAppGpLogContext, "Erase started for ", partition);

    erase.start = 0;
    erase.length = mtdInfo.size;

    if (ioctl(partitionFd, MEMERASE, &erase) != 0) {
        LOGE(&BlAppGpLogContext, "Failed to erase NOR partition");
        ret = -1;
        goto err;
    }

    LOGI(&BlAppGpLogContext, "Erase finished for ", partition);

    while (true)
	{
		bytesRead = read(SrcPart, bufferData, CHUNK_SIZE);

        if(bytesRead <= 0)
        {
            break;
        }

        ret = 0;
        ssize_t written = pwrite(partitionFd, bufferData, bytesRead, offset);
        if (written != (ssize_t)bytesRead) {
            perror("Write failed");
            LOGE(&BlAppGpLogContext, "Write failed at offset ", offset);
            delete[] bufferData;
            ret = -1;
            goto err;
        }
        offset += bytesRead;
        totalBytes += bytesRead;
    }

    delete[] bufferData;

    LOGI(&BlAppGpLogContext, "Flashing success of file : ", file,  " ,Total bytes written : ", totalBytes, " bytes");

err :
    if(SrcPart >= 0)
        close(SrcPart);
    if(partitionFd >= 0)
        close(partitionFd);
    return ret;
}

uint8_t FlashHandler::NorErase(std::string PackagePath)
{
	uint8_t Status = E_NOT_OK;
	char PackageName[100];
	int32_t fp;
	int32_t ret = EIO;
	struct mtd_info_user mtd;

	struct erase_info
	{
        uint32 start;
        uint32 length;
    } ei;

	strcpy(PackageName, PackagePath.c_str());

	if(PackageName != NULL)
	{
		fp = open(PackageName, O_WRONLY);

		if(fp >= 0)
		{
			ret = ioctl(fp, MEMGETINFO, &mtd);

			if (ret < 0)
			{
				printf ("\n Get MTD flash device info failed %d : %s", errno, strerror(errno));
			}
			else
			{
				ei.start = 0u;

				ei.length = mtd.erasesize;

				ret = ioctl(fp, MEMERASE, &ei);

				if(ret < 0)
				{
					printf ("\n MTD Erase Failed %d : %s", errno, strerror(errno));
				}
				else
				{
					Status = E_OK;
				}
			}
		}

		close(fp);
	}

	return Status;
}

uint8_t FlashHandler::EMMCErase(std::string PackagePath, uint32_t size)
{
	uint8_t Status = E_NOT_OK;

	int32_t sts = -1;

	std::string cmd;

	cmd = "tr '\000' '\377' < /dev/zero | dd of=/dev/mmcblk0 bs=512 seek=0x800 count=32768 conv=notrunc";

	sts = system(cmd.c_str());

	if(sts == E_OK)
	{
		Status = E_OK;
	}

	return Status;
}



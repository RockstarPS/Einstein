Imports System.Runtime.InteropServices

Public Class ClassVmfRemoteCLient
    '/*! ctrl message base */
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure vmf_bas_t
        Public msg_type As VMF_MSG_TYPE
        Public pid As Integer
        Public client_id As SByte
        Public msg_time As Integer
    End Structure


    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure id_t
        Public group As Byte
        Public vmf_event As Byte
    End Structure


    '/*! vmf-base */
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure vmf_msg_base_t
        Public base As vmf_bas_t
        Public id As id_t
    End Structure


    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure data_t
        Public length As UShort
        Public pl() As Byte
    End Structure


    ' /*! vmf basic msg */
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure vmf_basic_msg_t
        Public msg_base As vmf_msg_base_t
        Public data As data_t
        Public Sub New(ByVal data_len As UShort)
            ReDim data.pl(data_len)
            data.length = data_len
        End Sub
    End Structure


    ' /*! vmf basic msg */
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure vmf_most_msg_t
        Public msg_base As vmf_msg_base_t
        Public data As data_t
        Public tgt_addr As UShort
        Public src_addr As UShort
        Public channel_flag As Byte
        Public fblock_id As Byte
        Public inst_id As Byte
        Public func_id As UShort
        Public op_type As Byte
        Public Sub New(ByVal data_len As UShort)
            ReDim data.pl(data_len)
            data.length = data_len
        End Sub
    End Structure



    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure vmf_msg_t
        <FieldOffset(0)> Public vmf_basic_msg As vmf_basic_msg_t
        <FieldOffset(0)> Public vmf_most_msg As vmf_most_msg_t
        Public Sub New(ByVal data_len As UShort)
            ReDim vmf_most_msg.data.pl(data_len)
            ReDim vmf_basic_msg.data.pl(data_len)
        End Sub
    End Structure

    Public Const VMF_REM_MAX_DATA_SIZE = 2000


    Public Enum VMF_MSG_TYPE
        MSG_TYPE_MOST_MESSAGE = 1
        MSG_TYPE_BASIC_MESSAGE = 2
    End Enum

    Public Declare Auto Function VmfConnect Lib "remote_vmf_lib.dll" Alias "nw_vmf_connect" (<MarshalAsAttribute(UnmanagedType.LPStr)> ByVal proc_name As String, ByVal ihnore As Integer, ByVal ignore As UShort, ByVal msg_queue_size As UShort, ByVal msg_len As UShort) As Short
    Public Declare Auto Function VmfRegisterMsgGrp Lib "remote_vmf_lib.dll" Alias "nw_vmf_register_msg_group" (ByVal cid As SByte, ByVal GrpsNum As UShort, ByVal GrpsList() As Byte) As Short
    Public Declare Auto Function _VmfSendBasic Lib "remote_vmf_lib.dll" Alias "nw_vmf_send_basic" (ByVal cid As SByte, ByVal vmf_basic_msg() As Byte) As Short
    Declare Auto Function _VmfReceive Lib "remote_vmf_lib.dll" Alias "nw_vmf_receive" (ByVal cid As SByte, <MarshalAsAttribute(UnmanagedType.LPArray)> ByVal vmf_msg() As Byte, ByVal msg_length As UShort) As Short
    Public Declare Auto Function VmfRegisterMostFBlock Lib "remote_vmf_lib.dll" Alias "nw_vmf_register_most_fblock" (ByVal cid As SByte, ByVal FBlockId As Byte, ByVal InstId As Byte) As Short
    Public Declare Auto Function VmfRegisterMsgGrp Lib "remote_vmf_lib.dll" Alias "nw_vmf_register_msg_group" (ByVal cid As SByte, ByVal FBlockId As Byte, ByVal InstId As Byte, ByVal FuncIdsListLen As Short, ByVal FuncIds() As Byte) As Short
    Public Declare Auto Function VmfRegisterSpy Lib "remote_vmf_lib.dll" Alias "nw_vmf_register_spy" (ByVal cid As SByte) As Short
    Public Declare Auto Function VmfRegisterExtMostLink Lib "remote_vmf_lib.dll" Alias "nw_vmf_register_ext_most_link" (ByVal cid As SByte) As Short
    Declare Auto Function _VmfSendMostAsync Lib "remote_vmf_lib.dll" Alias "nw_vmf_send_most_async" (ByVal cid As SByte, ByVal vmf_basic_msg() As Byte) As Short
    Declare Auto Function _VmfSendMostCtrl Lib "remote_vmf_lib.dll" Alias "nw_vmf_send_most_ctrl" (ByVal cid As SByte, ByVal vmf_basic_msg() As Byte) As Short


    Shared Function ConvertAyToVmfBasicMsg(ByVal buffer() As Byte, ByRef vmf_basic_msg As vmf_basic_msg_t) As vmf_basic_msg_t
        Dim iCnt As Integer
        Dim iIndex = 0

        ' masg type (8)
        vmf_basic_msg.msg_base.base.msg_type = buffer(0)

        ' pid (32)
        vmf_basic_msg.msg_base.base.pid = ((((buffer(7) * 256) + (buffer(6)) * 256) + buffer(5)) * 256) + buffer(4)

        ' client_id (8)
        vmf_basic_msg.msg_base.base.client_id = buffer(8)

        ' client_time (32) ' only the lower 32 bits are copied
        vmf_basic_msg.msg_base.base.msg_time = ((((buffer(15) * 256) + (buffer(14)) * 256) + buffer(13)) * 256) + buffer(12)

        ' group (8)
        vmf_basic_msg.msg_base.id.group = buffer(12 + 8)
        ' event (8)
        vmf_basic_msg.msg_base.id.vmf_event = buffer(13 + 8)

        'length (16)
        vmf_basic_msg.data.length = (buffer(17 + 8) * 256) + buffer(16 + 8)

        ' transfer payload
        If vmf_basic_msg.data.length > 0 Then
            For iCnt = 0 To vmf_basic_msg.data.length - 1
                vmf_basic_msg.data.pl(iCnt) = buffer(18 + 8 + iCnt)
            Next iCnt
        End If

        Return vmf_basic_msg
    End Function
    Shared Function ConvertAyToVmfMostMsg(ByVal buffer() As Byte, ByRef vmf_most_msg As vmf_most_msg_t) As vmf_most_msg_t
        Dim iCnt As Integer

        ' masg type (8)
        vmf_most_msg.msg_base.base.msg_type = buffer(0)

        ' pid (32)
        vmf_most_msg.msg_base.base.pid = ((((buffer(7) * 256) + (buffer(6)) * 256) + buffer(5)) * 256) + buffer(4)

        ' client_id (8)
        vmf_most_msg.msg_base.base.client_id = buffer(8)

        ' client_time (32) ' only the lower 32 bits are copied
        vmf_most_msg.msg_base.base.msg_time = ((((buffer(15) * 256) + (buffer(14)) * 256) + buffer(13)) * 256) + buffer(12)

        ' group (8)
        vmf_most_msg.msg_base.id.group = buffer(12 + 8)
        ' event (8)
        vmf_most_msg.msg_base.id.vmf_event = buffer(13 + 8)

        ' target addr (16)
        vmf_most_msg.tgt_addr = buffer(16 + 8) + (buffer(17 + 8) * 256)

        ' src addr (16)
        vmf_most_msg.src_addr = buffer(18 + 8) + (buffer(19 + 8) * 256)

        ' channel flag (8)
        vmf_most_msg.channel_flag = buffer(20 + 8)

        ' fblock id (8)
        vmf_most_msg.fblock_id = buffer(21 + 8)

        ' Inst id (8)
        vmf_most_msg.inst_id = buffer(22 + 8)

        ' fct id (16)
        vmf_most_msg.func_id = buffer(24 + 8) + (buffer(25 + 8) * 256)

        ' op-type (8)
        vmf_most_msg.op_type = buffer(26 + 8)

        ' len (16)
        vmf_most_msg.data.length = buffer(28 + 8) + (buffer(29 + 8) * 256)

        ' data
        ' transfer payload
        If vmf_most_msg.data.length > 0 Then
            For iCnt = 0 To vmf_most_msg.data.length - 1
                vmf_most_msg.data.pl(iCnt) = buffer(30 + 8 + iCnt)
            Next iCnt
        End If

        Return vmf_most_msg
    End Function

    Shared Function ConvertAyToVmfMsg(ByVal buffer() As Byte, ByRef vmf_msg As vmf_msg_t) As vmf_msg_t

        ' check msg type
        vmf_msg.vmf_basic_msg.msg_base.base.msg_type = buffer(0)
        vmf_msg.vmf_most_msg.msg_base.base.msg_type = buffer(0)

        If vmf_msg.vmf_basic_msg.msg_base.base.msg_type = VMF_MSG_TYPE.MSG_TYPE_BASIC_MESSAGE Then
            ConvertAyToVmfBasicMsg(buffer, vmf_msg.vmf_basic_msg)
        Else
            ConvertAyToVmfMostMsg(buffer, vmf_msg.vmf_most_msg)
        End If
        Return vmf_msg
    End Function


    Shared Function ConvertVmfMsgToAy(ByRef buffer() As Byte, ByVal vmf_msg As vmf_msg_t) As Byte()

        If vmf_msg.vmf_basic_msg.msg_base.base.msg_type = VMF_MSG_TYPE.MSG_TYPE_BASIC_MESSAGE Then
            ConvertVmfBasicMsgToAy(buffer, vmf_msg.vmf_basic_msg)
        Else
            ConvertVmfMostMsgToAy(buffer, vmf_msg.vmf_most_msg)
        End If

        Return buffer
    End Function
    Shared Function ConvertVmfBasicMsgToAy(ByRef buffer() As Byte, ByVal vmf_basic_msg As vmf_basic_msg_t) As Byte()
        Dim iCnt As Integer

        ' masg type (8)
        buffer(0) = vmf_basic_msg.msg_base.base.msg_type

        ' fill
        buffer(1) = 0
        buffer(2) = 0
        buffer(3) = 0

        ' pid (32)
        buffer(4) = 99  ' ignore
        buffer(5) = 99
        buffer(6) = 99
        buffer(7) = 99

        ' client_id (8)
        buffer(8) = vmf_basic_msg.msg_base.base.client_id

        ' fill
        buffer(9) = 0
        buffer(10) = 0
        buffer(11) = 0

        ' time in clks
        buffer(12) = 0
        buffer(13) = 0
        buffer(14) = 0
        buffer(15) = 0
        buffer(16) = 0
        buffer(17) = 0
        buffer(18) = 0
        buffer(19) = 0

        ' group (8)
        buffer(12 + 8) = vmf_basic_msg.msg_base.id.group
        ' event (8)
        buffer(13 + 8) = vmf_basic_msg.msg_base.id.vmf_event

        ' fill
        buffer(14 + 8) = 0
        buffer(15 + 8) = 0

        'length (16)
        buffer(16 + 8) = (vmf_basic_msg.data.length And &HFF)
        buffer(17 + 8) = (vmf_basic_msg.data.length >> 8)

        ' transfer payload
        If vmf_basic_msg.data.length > 0 Then
            For iCnt = 0 To vmf_basic_msg.data.length - 1
                buffer(18 + 8 + iCnt) = vmf_basic_msg.data.pl(iCnt)
            Next iCnt
        End If

        Return buffer
    End Function

    Shared Function ConvertVmfMostMsgToAy(ByRef buffer() As Byte, ByVal vmf_Most_msg As vmf_most_msg_t) As Byte()
        Dim iCnt As Integer

        ' masg type (8)
        buffer(0) = vmf_Most_msg.msg_base.base.msg_type

        ' fill
        buffer(1) = 0
        buffer(2) = 0
        buffer(3) = 0

        ' pid (32)
        buffer(4) = 99  ' ignore
        buffer(5) = 99
        buffer(6) = 99
        buffer(7) = 99

        ' client_id (8)
        buffer(8) = vmf_Most_msg.msg_base.base.client_id

        ' fill
        buffer(9) = 0
        buffer(10) = 0
        buffer(11) = 0

        ' time in clks
        buffer(12) = 0
        buffer(13) = 0
        buffer(14) = 0
        buffer(15) = 0
        buffer(16) = 0
        buffer(17) = 0
        buffer(18) = 0
        buffer(19) = 0

        ' group (8)
        buffer(12 + 8) = vmf_Most_msg.msg_base.id.group
        ' event (8)
        buffer(13 + 8) = vmf_Most_msg.msg_base.id.vmf_event

        ' fill
        buffer(14 + 8) = 0
        buffer(15 + 8) = 0

        ' target addr (16)
        buffer(16 + 8) = (vmf_Most_msg.tgt_addr And &HFF)   ' low
        buffer(17 + 8) = (vmf_Most_msg.tgt_addr >> 8)   ' High

        ' src addr (16)
        buffer(18 + 8) = (vmf_Most_msg.src_addr And &HFF)   ' low
        buffer(19 + 8) = (vmf_Most_msg.src_addr >> 8)   ' High

        ' channel flag (8)
        buffer(20 + 8) = vmf_Most_msg.channel_flag

        ' fblock id (8)
        buffer(21 + 8) = vmf_Most_msg.fblock_id

        ' Inst id (8)
        buffer(22 + 8) = vmf_Most_msg.inst_id

        ' fill (8)
        buffer(23 + 8) = 0

        ' fct id (16)
        buffer(24 + 8) = (vmf_Most_msg.func_id And &HFF)   ' low
        buffer(25 + 8) = (vmf_Most_msg.func_id >> 8)   ' High

        ' op-type (8)
        buffer(26 + 8) = vmf_Most_msg.op_type

        ' fill (8)
        buffer(27 + 8) = 0

        ' len (16)
        buffer(28 + 8) = (vmf_Most_msg.data.length And &HFF)
        buffer(29 + 8) = (vmf_Most_msg.data.length >> 8)

        ' data
        ' transfer payload
        If vmf_Most_msg.data.length > 0 Then
            For iCnt = 0 To vmf_Most_msg.data.length - 1
                buffer(30 + 8 + iCnt) = vmf_Most_msg.data.pl(iCnt)
            Next iCnt
        End If

        Return buffer
    End Function

    Shared Function VmfSendBasic(ByVal cid As Byte, ByVal vmf_basic_msg As vmf_basic_msg_t) As Short
        Dim RetVal As SByte
        Dim Buffer(VMF_REM_MAX_DATA_SIZE) As Byte

        RetVal = _VmfSendBasic(cid, ConvertVmfBasicMsgToAy(Buffer, vmf_basic_msg))

        Return RetVal
    End Function
    Shared Function VmfSendMostAsync(ByVal cid As Byte, ByVal vmf_most_msg As vmf_most_msg_t) As Short
        Dim RetVal As Short
        Dim Buffer(VMF_REM_MAX_DATA_SIZE) As Byte

        RetVal = _VmfSendMostAsync(cid, ConvertVmfMostMsgToAy(Buffer, vmf_most_msg))

        Return RetVal
    End Function
    Shared Function VmfSendMostCtrl(ByVal cid As Byte, ByVal vmf_most_msg As vmf_most_msg_t) As Short
        Dim RetVal As Short
        Dim Buffer(VMF_REM_MAX_DATA_SIZE) As Byte

        RetVal = _VmfSendMostCtrl(cid, ConvertVmfMostMsgToAy(Buffer, vmf_most_msg))

        Return RetVal
    End Function

    Shared Function VmfReceive(ByVal cid As SByte, ByRef vmf_msg As vmf_msg_t, ByVal msg_length As UShort) As Short
        Dim RetVal As Short
        '        Dim Buffer(msg_length) As Byte
        Dim Buffer(VMF_REM_MAX_DATA_SIZE * 2) As Byte
        '        Dim myByteArray(msg_length) As Byte
        '        Dim myByteArrayAddress As IntPtr = System.Runtime.InteropServices.Marshal.UnsafeAddrOfPinnedArrayElement(myByteArray, 0)

        On Error Resume Next
        RetVal = _VmfReceive(cid, Buffer, msg_length)
        ConvertAyToVmfMsg(Buffer, vmf_msg)

        Return RetVal
    End Function
End Class


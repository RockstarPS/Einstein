Imports System.Runtime.InteropServices


Public Class Form1
    Const MAX__LISTBOX_ITEM_COUNT = 5000



    Dim thread As New Threading.Thread(AddressOf RecThread)
    Dim cid As Byte
    Delegate Sub SetTextCallback(ByVal [text] As String)

    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        thread.Abort()
    End Sub


    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'SetupGrid(Me.DataGridView1)
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim RetVal As SByte
        Dim Groups() As Byte = {12, 2, 4, 11}
        Dim vmf_msg As New ClassVmfRemoteCLient.vmf_msg_t(ClassVmfRemoteCLient.VMF_REM_MAX_DATA_SIZE)

        ' connect 
        RetVal = ClassVmfRemoteCLient.VmfConnect("VB-Test", 0, 0, 30, ClassVmfRemoteCLient.VMF_REM_MAX_DATA_SIZE)
        Me.Status.Text = "Cid =" & Format$(RetVal)

        If RetVal < 0 Then
            Me.Status.Text = "VmfConnect error Ret = " & RetVal
            Exit Sub
        End If
        cid = RetVal

        ' register groups
        '        RetVal = ClassVmfRemoteCLient.VmfRegisterMsgGrp(cid, Groups.Length, Groups)
        '        If RetVal < 0 Then
        '        Me.Status.Text = "VmfRegisterMsgGrp error Ret = " & RetVal
        '        Exit Sub
        '        End If

        ' register as spy
        RetVal = ClassVmfRemoteCLient.VmfRegisterSpy(cid)
        If RetVal < 0 Then
            Me.Status.Text = "VmfSendBasic error Ret = " & RetVal
            Exit Sub
        End If

        thread.Start()
        Me.Button2.Enabled = False
    End Sub
    Sub RecThread()
        Dim vmf_msg As New ClassVmfRemoteCLient.vmf_msg_t(ClassVmfRemoteCLient.VMF_REM_MAX_DATA_SIZE)
        Dim rRet As Short

        While True
            rRet = ClassVmfRemoteCLient.VmfReceive(cid, vmf_msg, ClassVmfRemoteCLient.VMF_REM_MAX_DATA_SIZE)
            If rRet > 0 Then
                WriteListbox(DecodeMsg(vmf_msg))
            End If
        End While

    End Sub

    Private Sub WriteListbox(ByVal [text] As String)
        'If these threads are different, it returns true.
        If Me.ListBox1.InvokeRequired Then
            Dim d As New SetTextCallback(AddressOf WriteListbox)
            Me.Invoke(d, New Object() {[text]})
        Else
            If Me.ListBox1.Items.Count > MAX__LISTBOX_ITEM_COUNT Then
                Me.ListBox1.Items.RemoveAt(0)
            End If
            Me.ListBox1.Items.Add(text)
            Me.ListBox1.SelectedIndex = Me.ListBox1.Items.Count - 1
            End If
    End Sub

    Private Function DecodeMsg(ByVal vmf_msg As ClassVmfRemoteCLient.vmf_msg_t) As String
        Dim DecMsg As String

        DecMsg = ""
        If vmf_msg.vmf_basic_msg.msg_base.base.msg_type = ClassVmfRemoteCLient.VMF_MSG_TYPE.MSG_TYPE_MOST_MESSAGE Then
            ' decode a MOST message
            DecMsg = "MOST " & vbTab

            DecMsg = DecMsg & "PID = " & vmf_msg.vmf_most_msg.msg_base.base.pid & vbTab
            DecMsg = DecMsg & "Src-Addr = 0x" & Hex4Nibble(vmf_msg.vmf_most_msg.src_addr)
            DecMsg = DecMsg & ", Trgt-Addr = 0x" & Hex4Nibble(vmf_msg.vmf_most_msg.tgt_addr)
            DecMsg = DecMsg & ", FktId = 0x" & Hex(vmf_msg.vmf_most_msg.func_id)
            DecMsg = DecMsg & ", FBId = 0x" & HexByte(vmf_msg.vmf_most_msg.fblock_id)
            DecMsg = DecMsg & ", InstId = 0x" & HexByte(vmf_msg.vmf_most_msg.inst_id)
            DecMsg = DecMsg & ", optype = 0x" & HexByte(vmf_msg.vmf_most_msg.op_type)
            DecMsg = DecMsg & ", data len = " & vmf_msg.vmf_most_msg.data.length
            ' print data
            If vmf_msg.vmf_most_msg.data.length > 0 Then
                Dim iCnt As Integer
                DecMsg = DecMsg & ", data: "
                For iCnt = 1 To vmf_msg.vmf_most_msg.data.length
                    DecMsg = DecMsg & HexByte(vmf_msg.vmf_most_msg.data.pl(iCnt - 1)) & " "
                Next iCnt
            End If
        Else
            ' decode a basic msg
            DecMsg = "BASIC " & vbTab
            DecMsg = DecMsg & "PID = " & vmf_msg.vmf_basic_msg.msg_base.base.pid & vbTab
            DecMsg = DecMsg & "Group = 0x" & HexByte(vmf_msg.vmf_basic_msg.msg_base.id.group)
            DecMsg = DecMsg & ", event = 0x" & HexByte(vmf_msg.vmf_basic_msg.msg_base.id.vmf_event)
            DecMsg = DecMsg & ", data len = " & vmf_msg.vmf_basic_msg.data.length
            If vmf_msg.vmf_basic_msg.data.length > 0 Then
                Dim iCnt As Integer
                DecMsg = DecMsg & ", data: "
                For iCnt = 1 To vmf_msg.vmf_basic_msg.data.length
                    DecMsg = DecMsg & HexByte(vmf_msg.vmf_basic_msg.data.pl(iCnt - 1)) & " "
                Next iCnt
            End If
        End If

        Return DecMsg
    End Function
    Function GetMsgTyp(ByVal vmf_msg As ClassVmfRemoteCLient.vmf_msg_t) As String
        Dim DecMsg As String

        If vmf_msg.vmf_basic_msg.msg_base.base.msg_type = ClassVmfRemoteCLient.VMF_MSG_TYPE.MSG_TYPE_MOST_MESSAGE Then
            ' decode a MOST message
            DecMsg = "MOST " & vbTab
        Else
            ' decode a basic msg
            DecMsg = "BASIC " & vbTab
        End If
        GetMsgTyp = DecMsg

    End Function
    Public Function HexByte(ByVal bIn As Byte) As String
        Dim stTmp As String

        'HexByte = Microsoft.VisualBasic.Right("00" & Format$(Hex(bIn)), 2)
        stTmp = "00" & Format$(Hex(bIn))
        HexByte = stTmp.Substring(stTmp.Length - 2)
    End Function
    Public Function Hex3Nibble(ByVal bIn As Short) As String
        Dim stTmp As String

        'HexByte = Microsoft.VisualBasic.Right("00" & Format$(Hex(bIn)), 2)
        stTmp = "000" & Format$(Hex(bIn))
        Hex3Nibble = stTmp.Substring(stTmp.Length - 3)
    End Function
    Public Function Hex4Nibble(ByVal bIn As UShort) As String
        Dim stTmp As String

        'HexByte = Microsoft.VisualBasic.Right("00" & Format$(Hex(bIn)), 2)
        stTmp = "0000" & Format$(Hex(bIn))
        Hex4Nibble = stTmp.Substring(stTmp.Length - 4)
    End Function

    Sub SetupGrid(ByVal myGrid As DataGridView)
        '        myGrid.Columns.Add("MsgType", "Message Type")
        '        myGrid.Columns.Add("Group", "Group")
        '        myGrid.Columns.Add("Event", "Event")
    End Sub

    Sub AddBasicData2Grid(ByVal myGrid As DataGridView)
        '  myGrid.Rows.Add()

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim vmf_most_msg As New ClassVmfRemoteCLient.vmf_most_msg_t(20)
        Dim RetVal As SByte

        ' send a MOST message
        vmf_most_msg.src_addr = &H100
        vmf_most_msg.tgt_addr = &H3C8
        vmf_most_msg.fblock_id = &HCA
        vmf_most_msg.inst_id = 0
        vmf_most_msg.func_id = &H247
        vmf_most_msg.op_type = &HC
        vmf_most_msg.data.pl(0) = 1
        vmf_most_msg.data.pl(1) = 2
        vmf_most_msg.data.pl(2) = 3
        vmf_most_msg.data.pl(3) = 4
        vmf_most_msg.data.length = 4
        RetVal = ClassVmfRemoteCLient.VmfSendMostCtrl(cid, vmf_most_msg)
        If RetVal < 0 Then
            Me.Status.Text = "VmfSendBasic error Ret = " & RetVal
            Exit Sub
        End If
    End Sub

    Private Sub Button1_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim vmf_bas_msg As New ClassVmfRemoteCLient.vmf_basic_msg_t(20)
        Dim RetVal As SByte
        Const REG_OPERATION = 10
        Const RegOprComplete = 2

        '/* create a basic message */
        vmf_bas_msg.msg_base.id.group = REG_OPERATION
        vmf_bas_msg.msg_base.id.vmf_event = RegOprComplete
        vmf_bas_msg.data.pl(0) = 1
        vmf_bas_msg.data.pl(1) = 2
        vmf_bas_msg.data.pl(2) = 3
        vmf_bas_msg.data.pl(3) = 4
        vmf_bas_msg.data.length = 4

        ' send basic message
        RetVal = ClassVmfRemoteCLient.VmfSendBasic(cid, vmf_bas_msg)
        If RetVal < 0 Then
            Me.Status.Text = "VmfSendBasic error Ret = " & RetVal
            Exit Sub
        End If
    End Sub
End Class

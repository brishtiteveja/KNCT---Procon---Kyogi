Public Class Form1

    'Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
    '    Dim LineOfText As String
    '    Dim i As Integer
    '    Dim aryTextFile() As String


    '    LineOfText = TextBox1.Text

    '    aryTextFile = LineOfText.Split(",")



    '    If TextBox1.Text <> "" Then
    '        Dim sizeOfary As Integer = aryTextFile.Length
    '        Dim removedStampString As String = ""




    '        Dim k As Integer = 0
    '        Dim stamp(sizeOfary / 2) As String
    '        Dim use(sizeOfary / 2) As String

    '        For i = 0 To sizeOfary - 1 Step 2
    '            stamp(k) = aryTextFile(i)
    '            use(k) = aryTextFile(i + 1)
    '            If use(k) = "0" Then
    '                removedStampString += stamp(k) + ","
    '            End If
    '            k += 1
    '        Next

    '        Dim linesInCmd As String = "0" + vbNewLine


    '        'check midddle answer




    '        linesInCmd += "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine

    '        k = 0
    '        For i = 0 To sizeOfary - 1 Step 2
    '            linesInCmd += stamp(k) + vbNewLine + use(k) + vbNewLine
    '            k += 1
    '        Next


    '        linesInCmd += "-1"

    '        My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)

    '        Label3.Text = removedStampString
    '    Else
    '        MsgBox("Please enter Stamp No you want to remove.. ")
    '    End If



    'End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim LineOfText As String
        Dim i As Integer
        Dim aryTextFile() As String


        LineOfText = TextBox1.Text

        aryTextFile = LineOfText.Split(" ")



        If TextBox1.Text <> "" Then
            Dim sizeOfary As Integer = aryTextFile.Length
            Dim removedStampString As String = ""




            Dim k As Integer = 0
            Dim stamp(sizeOfary) As String


            For i = 0 To sizeOfary - 1 Step 2
                stamp(k) = aryTextFile(i)
                k += 1
            Next

            Dim linesInCmd As String = "0" + vbNewLine


            'check midddle answer




            linesInCmd += "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine

            k = 0
            For i = 0 To sizeOfary - 1 Step 2
                linesInCmd += stamp(k) + vbNewLine + "0" + vbNewLine
                k += 1
            Next


            linesInCmd += "-1"

            My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)

            Label3.Text = removedStampString
        Else
            MsgBox("Please enter Stamp No you want to remove.. ")
        End If



    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim LineOfText As String
        Dim i As Integer
        Dim aryTextFile() As String


        LineOfText = TextBox1.Text

        aryTextFile = LineOfText.Split(",")




        
        Dim linesInCmd As String = "0" + vbNewLine
        linesInCmd += "3" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine

           

        linesInCmd += "-1"

        My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim LineOfText As String
        Dim i As Integer
        Dim aryTextFile() As String


        LineOfText = TextBox1.Text

        aryTextFile = LineOfText.Split(",")




        Dim linesInCmd As String = "0" + vbNewLine
        If TextBox2.Text = "" Then
            linesInCmd += "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine
        Else
            linesInCmd += "0" + vbNewLine + "0" + vbNewLine + TextBox2.Text + vbNewLine + "0" + vbNewLine

        End If


        linesInCmd += "-1"

        My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim LineOfText As String
        Dim aryTextFile() As String


        LineOfText = TextBox1.Text

        aryTextFile = LineOfText.Split(",")




        Dim linesInCmd As String = "0" + vbNewLine

        linesInCmd += "0" + vbNewLine + "1" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine


        linesInCmd += "-1"

        My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Dim LineOfText As String
        Dim aryTextFile() As String


        LineOfText = TextBox1.Text

        aryTextFile = LineOfText.Split(",")




        Dim linesInCmd As String = "0" + vbNewLine

        linesInCmd += "0" + vbNewLine + "2" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine


        linesInCmd += "-1"

        My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Dim LineOfText As String
        Dim i As Integer
        Dim aryTextFile() As String


        LineOfText = TextBox3.Text

        aryTextFile = LineOfText.Split(" ")



        If TextBox1.Text <> "" Then
            Dim sizeOfary As Integer = aryTextFile.Length
            Dim removedStampString As String = ""




            Dim k As Integer = 0
            Dim stamp(sizeOfary) As String


            For i = 0 To sizeOfary - 1 Step 2
                stamp(k) = aryTextFile(i)
                k += 1
            Next

            Dim linesInCmd As String = "0" + vbNewLine


            'check midddle answer




            linesInCmd += "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine + "0" + vbNewLine

            k = 0
            For i = 0 To sizeOfary - 1 Step 2
                linesInCmd += stamp(k) + vbNewLine + "1" + vbNewLine
                k += 1
            Next


            linesInCmd += "-1"

            My.Computer.FileSystem.WriteAllText("C:\kyogi\cmd.txt", linesInCmd, False)

            Label3.Text = removedStampString
        Else
            MsgBox("Please enter Stamp No you want to remove.. ")
        End If

    End Sub
End Class

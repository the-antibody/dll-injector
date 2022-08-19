Option Explicit

' Create notification
Dim box
box = MsgBox("This script will install the injector in your AppData." & vbCrLf & "Click 'OK' to install " & vbCrLf & "Click 'Cancel' to cancel.", 1 + 64 + vbSystemModal, "Installation Script")

' Check result
If box = 2 Then
    box = MsgBox("The installation has been cancelled.", 0 + 16, "Installation Script")
    WScript.Quit
End If

' Get shell and FSO
Dim shell, fso
Set shell = CreateObject("WScript.Shell")
Set fso = CreateObject("Scripting.FileSystemObject")

' Get current directory & app data folders
Dim current_dir : current_dir = fso.GetParentFolderName(WScript.ScriptFullName)
Dim appdata : appdata = shell.ExpandEnvironmentStrings("%APPDATA%")

' Sleep for 10 seconds
box = MsgBox("Downloading files now...", 0 + 64, "Installation Script")

' Download files
shell.Run "powershell -Command ""Invoke-WebRequest https://github.com/the-antibody/dll-injector/releases/download/1.0.0/inject.exe -OutFile inject.exe"""
shell.Run "powershell -Command ""Invoke-WebRequest https://github.com/the-antibody/dll-injector/releases/download/1.0.0/injector_gui.exe -OutFile injector_gui.exe"""

' Sleep for 2 seconds
WScript.Sleep(5000)

Dim target_folder : target_folder = appdata & "\dll-injector"

' Create folder in app data
fso.CreateFolder target_folder

' Move files to folder
fso.CopyFile current_dir & "\inject.exe", target_folder & "\inject.exe"
fso.CopyFile current_dir & "\injector_gui.exe", target_folder & "\injector_gui.exe"

' Prompt for desktop shortcut
box = MsgBox("Installed files successfully." & vbCrLf & "Would you like to create a desktop shortcut?", 4 + 32, "Installation Script")

' Check result
If box = 6 Then
    ' Create shortcut
    Dim link, desktop : desktop = shell.SpecialFolders("Desktop")
    Set link = shell.CreateShortcut(desktop & "\injector.lnk")

    link.Description = "Shortcut to encoder.exe"
    link.IconLocation = target_folder & "\injector_gui.exe,1"
    link.TargetPath = target_folder & "\injector_gui.exe"
    link.WorkingDirectory = target_folder
    link.Save

    box = MsgBox("Desktop shortcut created successfully.", 0 + 64, "Installation Script")
End If

' Final dialog
box = MsgBox("dll-injector was successfully installed.", 0 + 64, "Installation Script")

' Delete installed files
fso.DeleteFile current_dir & "\inject.exe"
fso.DeleteFile current_dir & "\injector_gui.exe"
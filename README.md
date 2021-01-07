# Terminal-Based-Linux-File-Explorer
Terminal Based file explorer works in two modes. Normal mode and Command Mode. In command mode, user can perform all operations of file explorer such as creating and deleting of file/directory, move, search, rename of the file, goto and many more. In normal mode user get GUI to navigate through different files &amp; folder.
###### Objective: 
Build a fully functional File Explorer Application, albeit with a restricted feature set.
File Explorer works in two modes -
  - Normal mode (default mode) - used to explore the current directory and navigate the filesystem
  - Command mode - used to enter shell commands
The root of the application will be the directory where the application was started.
It has the following functionalities -

##### NORMAL MODE :

  - Display a list of directories and files in the current foldera.Every file in the directory should be displayed on a new line with the following attributesfor each file -
      -  File Name
      - File Size
      - Ownership (user and group) and Permissions
      - Last modified
  - Open directories and files      
    When enter key is pressed -
      - Directory - Clear the screen and navigate into the directory and show the directory contents as specified in point 1
      - File - Open the file in vi editor
  - Traversal
      - Go back - Left arrow key should take the user to the previously visited directory
      - Go forward - Right arrow key should take the user to the next directory
      - Up one level - Backspace key should take the user up one level
      - Home - ​h​ key should take the user to the home folder (the folder where the applicationwas started)

##### COMMAND MODE:

  The application enters the Command button whenever “:” (colon) key is pressed. In the command mode, the user should be able to enter different commands. All commands appear in the status bar at the bottom.
  - Copy - ‘copy <source_file(s)> <destination_directory>’
    Move - ‘move <source_file(s)> <destination_directory>’
    Rename - ‘rename <old_filename> <new_filename>’
      - Eg copy foo.txt bar.txt baz.mp4 ~/foobar   
             move foo.txt bar.txt baz.mp4 ~/foobar   
             rename foo.txt bar.txt
      - Assume that the destination directory exists and you have write permissions.
      - Copying/Moving directories should also be implementedd.The file ownership and permissions should remain intact
  - Create File - ‘create_file <file_name> <destination_path>’
    Create Directory - ‘create_dir <dir_name> <destination_path>’
      - Eg -create_file foo.txt ~/foobar   
            create_file foo.txt .   
            create_dir foo ~/foobar
  - Delete File - ‘delete_file <file_path>’
    Delete Directory - ‘delete_dir <dir_path>’
    The file/dir path should be relative to the root from where the application is run
  - Goto - ‘goto <location>’
    - Eg - goto <directory_path>
    - Absolute path wrt application root will be given

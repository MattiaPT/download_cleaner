compile:
```
gcc -Wall -o .cleaner cleaner.c
```

### Set up for ~/Downloads folder (default):

- move *.cleaner* to ~

- run using ```./.cleaner```, when at ~ directory

### Custom set up:
- run using ```./.cleaner <rel_path>```,
  where *rel_path* points to the directory to clean
  relative to the current directory
  
### Setting up a cron job for the cleaner to run at startup:

open using ```crontab -e```, then add the following line:
```@reboot <path_to_cleaner>```

optionally add a log file to write the output of the cleaner to:
```@reboot <path_to_cleaner> >> <path_to_log>```

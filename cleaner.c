/*
 * Author: Mattia
 * Date: 14.10.2023
 *
 * This should be a simple program which resides in the home directory
 * and takes a folder, which the user does not want to get cluttered:
 * On startup it should run and check if any of the present files
 * in the directory live long enough to be automatically deleted again.
 *
 */

#include "cleaner.h"

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define DEFAULT_FOLDER "/Downloads"

#define CRITERION(metadata) (int)metadata.st_mtime
#define MAX_LIFETIME_S 604800

int main(int argc, char *argv[]) {
  char folder_to_clean[256] = DEFAULT_FOLDER;
  if (argc > 1) {
    strcpy(folder_to_clean, argv[1]);
  }
  DIR *d = opendir(folder_to_clean);
  struct dirent *dir;

  const int current_time = (int)time(NULL);

  if (d) {
    char base[256];
    while ((dir = readdir(d)) != NULL) {
      base[0] = '\0';
      strcpy(base, folder_to_clean);
      strcat(base, dir->d_name);

      struct stat metadata;
      stat(base, &metadata);

      int timestamp = CRITERION(metadata);

      if (timestamp + MAX_LIFETIME_S < current_time) {
        printf("%d to delete: %s\n", timestamp, base);
      }
    }
    closedir(d);
  }

  return 0;
}

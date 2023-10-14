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

#define DEFAULT_FOLDER "/Downloads"

int main(int argc, char *argv[]) {
  char folder_to_clean[256] = DEFAULT_FOLDER;
  if (argc > 1) {
    strcpy(folder_to_clean, argv[1]);
  }
  DIR *d = opendir(folder_to_clean);
  struct dirent *dir;

  if (d) {
    char base[256];
    while ((dir = readdir(d)) != NULL) {
      strcpy(base, folder_to_clean);
      strcat(base, dir->d_name);

      struct stat metadata;
      stat(folder_to_clean, &metadata);
      printf("%llu\n\n\n", (long long)metadata.st_mtime);
      base[0] = '\0';
    }
    closedir(d);
  }
  return 0;
}

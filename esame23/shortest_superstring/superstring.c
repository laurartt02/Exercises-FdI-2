#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <stdlib.h>

#include <stdbool.h>


static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}


char* SolveSuperstring(const char** v, size_t v_size) {
  
    char* option = NULL;
    int overlapping = 0;
    char* best_option = NULL;
    int best_overlapping = -1;
    size_t index1 = 0;
    size_t index2 = 0;
    bool* used = calloc(v_size, sizeof(bool));
    for (size_t i = 0; i < v_size - 1; ++i) {
        for (size_t j = i + 1; j < v_size; ++j) {
            option = Overlap(v[i], v[j], &overlapping);
            if (overlapping > best_overlapping) {
                free(best_option);
                best_option = option;
                best_overlapping = overlapping;
                index1 = i;
                index2 = j;
            }
            else {
                free(option);
            }
        }
    }
    used[index1] = true;
    used[index2] = true;
    size_t len = strlen(best_option);
    char* ret = malloc((len + 1) * sizeof(char));
    strcpy(ret, best_option);
    bool check = false;
    while (!check) {
        check = true;
        best_overlapping = -1;
        for (size_t k = 0; k < v_size; ++k) {
            if (!used[k]) {
                option = Overlap(ret, v[k], &overlapping);
                if (overlapping > best_overlapping) {
                    free(best_option);
                    best_option = option;
                    best_overlapping = overlapping;
                    index1 = k;
                }
                else {
                    free(option);
                }

            }
        }
        used[index1] = true;
        len = strlen(best_option);
        ret = realloc(ret, (len + 1) * sizeof(char));
        strcpy(ret, best_option);
        
        for (size_t a = 0; a < v_size; ++a) {
            if (!used[a]) {
                check = false;
                break;
            } 
        }
    }
    free(best_option);
    free(used);
    return ret;
}
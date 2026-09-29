#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMDS 5
#define TOKENS 4
#define MAXWORDS 100
int main() {
    int cl[CMDS] = {0};
    char *lists[CMDS][MAXWORDS];
    char *tokens[TOKENS] = {"[N]", "[AV]", "[V]", "[AJ]"};
    char *cmds[CMDS] = {"NOUNS", "ADVERBS", "VERBS", "ADJECTIVES", "END"};
    char template_line[1024] = "";
    char line[1024];
    if (fgets(template_line, sizeof(template_line), stdin) == NULL) {
        return 0;
    }
    template_line[strcspn(template_line, "\r\n")] = '\0';
    int current_cmd = -1;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;
        int matched = -1;
        for (int i = 0; i < CMDS; i++) {
            if (strcmp(line, cmds[i]) == 0) {
                matched = i;
                break;
            }
        }
        if (matched != -1) {
            current_cmd = matched;
            if (current_cmd == 4) break; // "END"
        } else if (current_cmd >= 0 && current_cmd < TOKENS) {
            lists[current_cmd][cl[current_cmd]] = strdup(line);
            cl[current_cmd]++;
        }
    }
    int ptrs[TOKENS] = {0};
    for (int count = 0; count < 2; count++) {
        char output[2048] = "";
        char *cursor = template_line;
        while (*cursor) {
            int replaced = 0;
            for (int t = 0; t < TOKENS; t++) {
                int tlen = strlen(tokens[t]);
                if (strncmp(cursor, tokens[t], tlen) == 0) {
                    if (cl[t] > 0) {
                        strcat(output, lists[t][ptrs[t] % cl[t]]);
                        ptrs[t]++;
                    }
                    cursor += tlen;
                    replaced = 1;
                    break;
                }
            }
            if (!replaced) {
                int len = strlen(output);
                output[len] = *cursor;
                output[len + 1] = '\0';
                cursor++;
            }
        }
        printf("%s\n", output);
    }
    return 0;
}
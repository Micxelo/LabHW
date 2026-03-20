#include <stdio.h>
#include <string.h>
#include "utils.h"

void process_input(char *input) {
	char *p = input;
	char first_letters[200] = { };
	char longest_word[200] = { };
	char current_word[200] = { };
	int word_count = 0;
	int max_length = 0;

	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';

	/* 跳过开头的空格 */
	while (*p == ' ')
		p++;

	int current_word_index = 0;

	while (*p) {
		if (*p == ' ') {
			if (current_word_index > 0) {
				current_word[current_word_index] = '\0';

				/* 记录首字母 */
				first_letters[word_count] = current_word[0];

				/* 更新最长单词 */
				if (current_word_index > max_length) {
					max_length = current_word_index;
					strcpy(longest_word, current_word);
				}

				word_count++;
				current_word_index = 0;
			}

			while (*p == ' ')
				p++;

			if (*p)
				putchar(' ');
		} else {
			putchar(*p);
			current_word[current_word_index++] = *p;
			p++;
		}
	}

	/* 处理最后一个单词 */
	if (current_word_index > 0) {
		current_word[current_word_index] = '\0';
		first_letters[word_count] = current_word[0];
		if (current_word_index > max_length) {
			strcpy(longest_word, current_word);
		}
		word_count++;
	}

	putchar('\n');
	printf("%d\n", word_count);
	printf("%s\n", first_letters);
	printf("%s\n", longest_word);
}

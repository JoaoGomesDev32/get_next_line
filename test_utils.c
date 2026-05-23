#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*result;

	// ft_strlen
	printf("=== ft_strlen ===\n");
	printf("%zu\n", ft_strlen("hello"));     // 5
	printf("%zu\n", ft_strlen(""));          // 0
	printf("%zu\n", ft_strlen(NULL));        // 0

	// ft_strchr
	printf("=== ft_strchr ===\n");
	printf("%s\n", ft_strchr("hello\nworld", '\n')); // \nworld
	printf("%p\n", ft_strchr("hello", '\n'));         // (null)

	// ft_strdup
	printf("=== ft_strdup ===\n");
	result = ft_strdup("hello");
	printf("%s\n", result);   // hello
	free(result);

	// ft_strjoin
	printf("=== ft_strjoin ===\n");
	result = ft_strjoin("hello", "\nworld");
	printf("[%s]\n", result);   // devia mostrar [hello\nworld] em duas linhas
	printf("len: %zu\n", ft_strlen(result));  // devia mostrar 11
	free(result);
	result = ft_strjoin(NULL, "world");
	printf("%s\n", result);   // world
	free(result);

	// ft_substr
	printf("=== ft_substr ===\n");
	result = ft_substr("hello world", 6, 5);
	printf("%s\n", result);   // world
	free(result);
	result = ft_substr("hello", 10, 5);
	printf("[%s]\n", result);   // devia mostrar []
	free(result);

	return (0);
}
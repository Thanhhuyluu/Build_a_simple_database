ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    size_t pos = 0;
    int c;

    if (*lineptr == NULL || *n == 0) {
        *n = 128;  
        *lineptr = malloc(*n);
        if (*lineptr == NULL) return -1;
    }

    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *n) {
            *n *= 2;
            char *new_ptr = realloc(*lineptr, *n);
            if (new_ptr == NULL) return -1;
            *lineptr = new_ptr;
        }

        (*lineptr)[pos++] = c;

        if (c == '\n') break;
    }

    if (pos == 0) return -1;

    (*lineptr)[pos] = '\0';
    return pos;
}

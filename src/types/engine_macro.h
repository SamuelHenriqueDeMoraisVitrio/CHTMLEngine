
#define CreateTextInEngine(name, ...) \
    const char* name(void) { \
        return #__VA_ARGS__; \
    }


#ifndef PRIVATE_TYPES_CTEXTENGINE_ENGINE_MACRO
#define PRIVATE_TYPES_CTEXTENGINE_ENGINE_MACRO

#define CreateTextInEngine(name, ...) \
    const char* name(void) { \
        return #__VA_ARGS__; \
    }

#endif //PRIVATE_TYPES_CTEXTENGINE_ENGINE_MACRO

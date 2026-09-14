#ifndef HMI_LANGUAGE_INTERFACE_H
#define HMI_LANGUAGE_INTERFACE_H

#define HMI_CHAR_PTR(x)

#ifdef LNG_UNICODE
     #define _HMI_CHAR_
     typedef wchar_t HMI_CHAR;
#else
     typedef char HMI_CHAR;
#endif

#endif
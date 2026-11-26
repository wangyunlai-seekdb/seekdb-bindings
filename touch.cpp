#include <cstddef>
#if defined(__ANDROID__) && defined(__aarch64__)
// The static ARM64 Android probe needs the Bionic TLS segment alignment.
alignas(64) static thread_local volatile unsigned char bionic_tls_alignment;
#endif

void touch_frame(volatile char *frame, size_t size) {
#if defined(__ANDROID__) && defined(__aarch64__)
  bionic_tls_alignment = 1;
#endif
  for (size_t offset = 0; offset < size; offset += 4096) frame[offset] = 7;
  frame[size - 1] = 11;
}

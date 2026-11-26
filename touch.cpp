#include <cstddef>
#if defined(__ANDROID__) && defined(__aarch64__)
// The standalone static Android probe needs an explicitly aligned ELF TLS section.
__asm__(".pushsection .tbss,\"awT\",%nobits\n"
        ".p2align 6\n"
        ".global seekdb_probe_tls_alignment\n"
        "seekdb_probe_tls_alignment:\n"
        ".zero 64\n"
        ".popsection\n");
#endif

void touch_frame(volatile char *frame, size_t size) {
  for (size_t offset = 0; offset < size; offset += 4096) frame[offset] = 7;
  frame[size - 1] = 11;
}

// flags = 1: -w, 2: -s, 4: -g, 8: -r, 16: -y
int get_flags(int argc, char** argv) {
  int flags = 0;

  for (int i = 1; i < argc; i++)
    if (argv[i][0] == '-')
      for (char* letter = &argv[i][1]; *letter != 0; letter++)
        flags += *letter == 'w' && !(flags & 1 << 0) ? 1 << 0:
                 *letter == 's' && !(flags & 1 << 1) ? 1 << 1:
                 *letter == 'y' && !(flags & 1 << 2) ? 1 << 2:
                 *letter == 'g' && !(flags & 1 << 3) ? 1 << 3:
                 *letter == 'r' && !(flags & 1 << 4) ? 1 << 4:
                 0;

  return flags;
}

/* @JUDGE_ID: 19899RK 342 C++11 "By Anadan" */
// HTML Syntax Checking
// Accepted (0.010 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <string>
#include <vector>

struct Buffer {
  static constexpr int length = 1024 * 3;
  char begin[length];
  char* const end_minus_one = begin + (length - 2);
};

// Returns true if EOL or EOF was reached.
bool ReadLine(Buffer& buffer, const int offset = 0) {
  *buffer.end_minus_one = 0;
  if (!std::fgets(buffer.begin + offset, buffer.length - offset, stdin)) {
    // Assume EOF is reached, return empty string.
    buffer.begin[offset] = 0;
    return true;
  }
  return *buffer.end_minus_one == 0 || *buffer.end_minus_one == '\n';
}

void ReadUntilEOL(Buffer& buffer) {
  while (!ReadLine(buffer)) {
    // continue;
  }
}

// Returns error code:
// 1. line #: bad character in tag name
// 2. line #: too many/few characters in tag name
// 3. line #: expected </xxxxxxxxxx>
// 4. line #: no matching begin tag.
int ReadAndProcessLine(std::vector<std::string>& tags, Buffer& buffer) {
  int read_offset = 0;
  while (1) {
    const bool done = ReadLine(buffer, read_offset);
    read_offset = 0;
    // Find all HTML tags.
    for (const char* ptr = buffer.begin; *ptr; ++ptr) {
      if (*ptr != '<') continue;
      const char* tag_begin = ptr + 1;
      bool is_open_tag = true;
      if (*tag_begin == '/') {
        is_open_tag = false;
        ++tag_begin;
      }
      const char* tag_end = tag_begin;
      for (; *tag_end && *tag_end != '>'; ++tag_end) {
        if (*tag_end < 'A' || *tag_end > 'Z') {
          if (!done) ReadUntilEOL(buffer);
          return 1;
        }
        if (tag_end - tag_begin + 1 > 10) {
          if (!done) ReadUntilEOL(buffer);
          return 2;
        }
      }
      // Handle special case when a line break was in the middle of a tag.
      // Copy the read part of the tag to the beginning of the buffer.
      if (*tag_end == 0) {
        assert(!done);
        while (*ptr) buffer.begin[read_offset++] = *ptr++;
        break;
      }
      const int tag_length = tag_end - tag_begin;
      if (tag_length < 1 || tag_length > 10) {
        if (!done) ReadUntilEOL(buffer);
        return 2;
      }
      if (is_open_tag) {
        tags.emplace_back(tag_begin, tag_length);
      } else if (tags.empty()) {
        if (!done) ReadUntilEOL(buffer);
        return 4;
      } else if (tags.back().size() != tag_length ||
                 tags.back() != std::string(tag_begin, tag_length)) {
        if (!done) ReadUntilEOL(buffer);
        return 3;
      } else {
        tags.pop_back();
      }
    }
    if (done) break;
  }
  return 0;
}

int main() {
  int testcase = 0, NL;
  std::vector<std::string> tags;
  Buffer buffer;

  while (std::scanf("%d", &NL) == 1 && NL) {
    ReadUntilEOL(buffer);
    tags.clear();

    int line = 0, error_code = 0;
    for (; line < NL; ++line) {
      error_code = ReadAndProcessLine(tags, buffer);
      if (error_code != 0) {
        for (int i = ++line; i < NL; ++i) {
          ReadUntilEOL(buffer);
        }
        break;
      }
    }
    if (error_code == 0 && !tags.empty()) {
      error_code = 3;
    }

    std::printf("Test Case %d\n", ++testcase);
    switch (error_code) {
      case 0:
        std::puts("OK");
        break;
      case 1:
        std::printf("line %d: bad character in tag name.\n", line);
        break;
      case 2:
        std::printf("line %d: too many/few characters in tag name.\n", line);
        break;
      case 3:
        std::printf("line %d: expected </%s>\n", line, tags.back().c_str());
        break;
      case 4:
        std::printf("line %d: no matching begin tag.\n", line);
        break;
      default:
        assert(0 <= error_code && error_code < 5);
        break;
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

/* @JUDGE_ID: 19899RK 226 C++ "By Anadan" */
// MIDI Preprocessing
// Accepted (0.010 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

struct MidiCommand {
  int time, freq;
  bool off;
};

void solve(std::vector<MidiCommand>& commands) {
  int last_on_index[128], nested[128];
  std::vector<MidiCommand> wave;
  for (int i = 0; i < 128; ++i) {
    last_on_index[i] = -1;
    nested[i] = 0;
  }
  for (int i = 0; i < commands.size(); ++i) {
    const int time = commands[i].time;
    wave.clear();
    for (; i < commands.size() && commands[i].time == time; ++i) {
      MidiCommand& cmd = commands[i];
      bool eliminated = false;
      const int prev_on = last_on_index[cmd.freq];
      if (!cmd.off && nested[cmd.freq] && prev_on != -1 &&
          commands[prev_on].time == cmd.time - 1) {
        eliminated = true;
      }
      nested[cmd.freq] += cmd.off ? -1 : 1;
      assert(nested[cmd.freq] >= 0);
      if (cmd.off && nested[cmd.freq]) {
        eliminated = true;
      }
      if (!cmd.off) last_on_index[cmd.freq] = i;
      if (!eliminated) {
        if (!cmd.off && nested[cmd.freq] > 1) {
          std::printf("%d OFF %d\n", cmd.time - 1, cmd.freq);
        }
        wave.push_back(std::move(cmd));
      }
    }
    for (int j = 0; j < wave.size(); ++j) {
      const MidiCommand& cmd = wave[j];
      if (cmd.off) {
        std::printf("%d OFF %d\n", cmd.time, cmd.freq);
      } else {
        std::printf("%d ON %d\n", cmd.time, cmd.freq);
      }
    }
    --i;
  }
}

int main() {
  char buffer[4];
  int last_off_index[128];
  int time, freq;
  std::vector<MidiCommand> commands;
  while (1) {
    commands.clear();
    for (int i = 0; i < 128; ++i) {
      last_off_index[i] = -1;
    }
    while (std::scanf("%d", &time) == 1 && time >= 0) {
      std::scanf("%s%d\n", buffer, &freq);
      const bool off = (buffer[1] == 'F');
      MidiCommand cmd;
      cmd.time = time;
      cmd.freq = freq;
      cmd.off = off;
      commands.push_back(std::move(cmd));

      const int prev_off = last_off_index[freq];
      if (!off && prev_off != -1 && commands[prev_off].time == time) {
        std::swap(commands[prev_off], commands.back());
        last_off_index[freq] = commands.size() - 1;
      } else {
        if (off) last_off_index[freq] = commands.size() - 1;
      }
    }
    solve(commands);
    std::printf("%d\n", time);
    if (time == -2) break;
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

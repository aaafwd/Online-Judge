/* @JUDGE_ID: 19899RK 212 C++11 "By Anadan" */
// Use of Hospital Facilities
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <vector>

struct Patient {
  char name[12];
  int surgery_mins, recovery_mins, roster;
  int room, room_begin, room_end;
  int bed, bed_begin, bed_end;
  // 0 - in operation
  // 1 - out of operation, in transit to bed
  // 2 - out of bed, recovered
  int state = 0;
  int time = 0;
};

struct Hospital {
  int rooms, beds, start_hour, transport_mins;
  int prepare_room_mins, prepare_bed_mins;
};

struct Utilization {
  int available_time = 0;
  int used_time = 0;
};

void AssignPatient(const int time, const int prepare_room_mins,
                   Patient& patient, const int room_index, Utilization& room) {
  patient.room = room_index;
  patient.room_begin = time;
  patient.room_end = time + patient.surgery_mins;
  patient.time = patient.room_end;
  room.available_time = patient.time + prepare_room_mins;
  room.used_time += patient.surgery_mins;
}

void solve(const Hospital& h, std::vector<Patient>& patients) {
  auto cmp = [&patients](const int i, const int j) {
    const Patient& a = patients[i];
    const Patient& b = patients[j];
    if (a.time != b.time) return a.time > b.time;
    if (a.state != b.state) return a.state < b.state;
    return a.room > b.room;
  };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> queue(cmp);
  std::vector<Utilization> rooms(h.rooms);
  std::vector<Utilization> beds(h.beds);

  int next_patient = 0;
  for (int r = 0; r < h.rooms && next_patient < patients.size(); ++r) {
    AssignPatient(0, h.prepare_room_mins, patients[next_patient], r, rooms[r]);
    queue.push(next_patient++);
  }

  while (!queue.empty()) {
    const int index = queue.top();
    queue.pop();
    Patient& p = patients[index];
    ++p.state;
    if (p.state == 1) {
      // Out of operation. Find first available bed.
      int bed = 0;
      for (; bed < beds.size(); ++bed) {
        if (beds[bed].available_time <= p.time) break;
      }
      assert(bed < beds.size());

      p.time += h.transport_mins;
      p.bed = bed;
      p.bed_begin = p.time;
      p.bed_end = p.time + p.recovery_mins;
      p.time = p.bed_end;
      beds[bed].available_time = p.bed_end + h.prepare_bed_mins;
      beds[bed].used_time += p.recovery_mins;
      queue.push(index);

      // Assign next patient, if any.
      if (next_patient < patients.size()) {
        const int room_index = p.room;
        Utilization& room = rooms[room_index];
        AssignPatient(room.available_time, h.prepare_room_mins,
                      patients[next_patient], room_index, room);
        queue.push(next_patient++);
      }
    } else {
      // Out of bed.
      assert(p.state == 2);
    }
  }
  assert(next_patient == patients.size());

  std::puts(" Patient          Operating Room          Recovery Room");
  std::puts(" #  Name     Room#  Begin   End      Bed#  Begin    End");
  std::puts(" ------------------------------------------------------");
  const int time_offset = h.start_hour * 60;
  int max_end_time = 0;
  for (int i = 0; i < patients.size(); ++i) {
    Patient& p = patients[i];
    p.room_begin += time_offset;
    p.room_end += time_offset;
    p.bed_begin += time_offset;
    p.bed_end += time_offset;
    if (max_end_time < p.bed_end) max_end_time = p.bed_end;
    std::printf(
        "%2d  %-10s%2d   %2d:%02d   %2d:%02d     %2d   %2d:%02d   %2d:%02d\n",
        i + 1, p.name, p.room + 1, p.room_begin / 60, p.room_begin % 60,
        p.room_end / 60, p.room_end % 60, p.bed + 1, p.bed_begin / 60,
        p.bed_begin % 60, p.bed_end / 60, p.bed_end % 60);
  }

  const int total_util_time = max_end_time - time_offset;
  assert(total_util_time > 0);
  std::puts("\nFacility Utilization");
  std::puts("Type  # Minutes  % Used");
  std::puts("-------------------------");
  for (int i = 0; i < rooms.size(); ++i) {
    const Utilization& room = rooms[i];
    double ratio = room.used_time * 100;
    ratio /= total_util_time;
    ratio += 1e-8;
    std::printf("Room %2d %7d  %6.2lf\n", i + 1, room.used_time, ratio);
  }
  for (int i = 0; i < beds.size(); ++i) {
    const Utilization& bed = beds[i];
    double ratio = bed.used_time * 100;
    ratio /= total_util_time;
    ratio += 1e-8;
    std::printf("Bed %3d %7d  %6.2lf\n", i + 1, bed.used_time, ratio);
  }
  std::putchar('\n');
}

int main() {
  int N;
  Hospital h;
  std::vector<Patient> patients;
  patients.reserve(100);
  while (std::scanf("%d%d%d%d%d%d%d", &h.rooms, &h.beds, &h.start_hour,
                    &h.transport_mins, &h.prepare_room_mins,
                    &h.prepare_bed_mins, &N) == 7) {
    patients.clear();
    patients.resize(N);
    for (int i = 0; i < N; ++i) {
      Patient& p = patients[i];
      std::scanf("%s%d%d", p.name, &p.surgery_mins, &p.recovery_mins);
      p.roster = i;
    }
    solve(h, patients);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */


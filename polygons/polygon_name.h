#pragma once
#include <optional>
#include <string>
#include <unordered_map>

namespace PolygonName {

struct PolygonName {
  std::string primary;
  std::optional<std::string> secondary;
};

PolygonName GetPolygonName(const size_t& n);

const std::unordered_map<size_t, PolygonName> polygon_names_pre = {
    {1, {"monogon"}},
    {2, {"digon"}},
    {3, {"triangle", "trigon"}},
    {4, {"quadrilateral", "tetragon"}},
    {5, {"pentagon"}},
    {6, {"hexagon"}},
    {7, {"heptagon", "septagon"}},
    {8, {"octagon"}},
    {9, {"nonagon", "enneagon"}},
    {10, {"decagon"}},
    {11, {"hendecagon", "undecagon"}},
    {12, {"dodecagon", "duodecagon"}},
    {13, {"tridecagon", "triskaidecagon"}},
    {14, {"tetradecagon", "tetrakaidecagon"}},
    {15, {"pentadecagon", "pentakaidecagon"}},
    {16, {"hexadecagon", "hexakaidecagon"}},
    {17, {"heptadecagon", "heptakaidecagon"}},
    {18, {"octadecagon", "octakaidecagon"}},
    {19, {"enneadecagon", "enneakaidecagon"}},
    {20, {"icosagon"}},
    {21, {"icosihenagon", "icosikaihenagon"}},
    {22, {"icosidigon", "icosikaidigon"}},
    {23, {"icositrigon", "icosikaitrigon"}},
    {24, {"icositetragon", "icosikaitetragon"}},
    {25, {"icosipentagon", "icosikaipentagon"}},
    {26, {"icosihexagon", "icosikaihexagon"}},
    {27, {"icosiheptagon", "icosikaiheptagon"}},
    {28, {"icosioctagon", "icosikaioctagon"}},
    {29, {"icosienneagon", "icosikaienneagon"}},
    {30, {"triacontagon"}},
    {31, {"triacontahenagon", "triacontakaihenagon"}},
    {32, {"triacontadigon", "triacontakaidigon"}},
    {33, {"triacontatrigon", "triacontakaitrigon"}},
    {34, {"triacontatetragon", "triacontakaitetragon"}},
    {35, {"triacontapentagon", "triacontakaipentagon"}},
    {36, {"triacontahexagon", "triacontakaihexagon"}},
    {37, {"triacontaheptagon", "triacontakaiheptagon"}},
    {38, {"triacontaoctagon", "triacontakaioctagon"}},
    {39, {"triacontaenneagon", "triacontakaienneagon"}},
    {40, {"tetracontagon"}},
    {41, {"tetracontahenagon", "tetracontakaihenagon"}},
    {42, {"tetracontadigon", "tetracontakaidigon"}},
    {43, {"tetracontatrigon", "tetracontakaitrigon"}},
    {44, {"tetracontatetragon", "tetracontakaitetragon"}},
    {45, {"tetracontapentagon", "tetracontakaipentagon"}},
    {46, {"tetracontahexagon", "tetracontakaihexagon"}},
    {47, {"tetracontaheptagon", "tetracontakaiheptagon"}},
    {48, {"tetracontaoctagon", "tetracontakaioctagon"}},
    {49, {"tetracontaenneagon", "tetracontakaienneagon"}},
    {50, {"pentacontagon"}},
    {51, {"pentacontahenagon", "pentacontakaihenagon"}},
    {52, {"pentacontadigon", "pentacontakaidigon"}},
    {53, {"pentacontatrigon", "pentacontakaitrigon"}},
    {54, {"pentacontatetragon", "pentacontakaitetragon"}},
    {55, {"pentacontapentagon", "pentacontakaipentagon"}},
    {56, {"pentacontahexagon", "pentacontakaihexagon"}},
    {57, {"pentacontaheptagon", "pentacontakaiheptagon"}},
    {58, {"pentacontaoctagon", "pentacontakaioctagon"}},
    {59, {"pentacontaenneagon", "pentacontakaienneagon"}},
    {60, {"hexacontagon"}},
    {61, {"hexacontahenagon", "hexacontakaihenagon"}},
    {62, {"hexacontadigon", "hexacontakaidigon"}},
    {63, {"hexacontatrigon", "hexacontakaitrigon"}},
    {64, {"hexacontatetragon", "hexacontakaitetragon"}},
    {65, {"hexacontapentagon", "hexacontakaipentagon"}},
    {66, {"hexacontahexagon", "hexacontakaihexagon"}},
    {67, {"hexacontaheptagon", "hexacontakaiheptagon"}},
    {68, {"hexacontaoctagon", "hexacontakaioctagon"}},
    {69, {"hexacontaenneagon", "hexacontakaienneagon"}},
    {70, {"heptacontagon"}},
    {71, {"heptacontahenagon", "heptacontakaihenagon"}},
    {72, {"heptacontadigon", "heptacontakaidigon"}},
    {73, {"heptacontatrigon", "heptacontakaitrigon"}},
    {74, {"heptacontatetragon", "heptacontakaitetragon"}},
    {75, {"heptacontapentagon", "heptacontakaipentagon"}},
    {76, {"heptacontahexagon", "heptacontakaihexagon"}},
    {77, {"heptacontaheptagon", "heptacontakaiheptagon"}},
    {78, {"heptacontaoctagon", "heptacontakaioctagon"}},
    {79, {"heptacontaenneagon", "heptacontakaienneagon"}},
    {80, {"octacontagon"}},
    {81, {"octacontahenagon", "octacontakaihenagon"}},
    {82, {"octacontadigon", "octacontakaidigon"}},
    {83, {"octacontatrigon", "octacontakaitrigon"}},
    {84, {"octacontatetragon", "octacontakaitetragon"}},
    {85, {"octacontapentagon", "octacontakaipentagon"}},
    {86, {"octacontahexagon", "octacontakaihexagon"}},
    {87, {"octacontaheptagon", "octacontakaiheptagon"}},
    {88, {"octacontaoctagon", "octacontakaioctagon"}},
    {89, {"octacontaenneagon", "octacontakaienneagon"}},
    {90, {"enneacontagon"}},
    {91, {"enneacontahenagon", "enneacontakaihenagon"}},
    {92, {"enneacontadigon", "enneacontakaidigon"}},
    {93, {"enneacontatrigon", "enneacontakaitrigon"}},
    {94, {"enneacontatetragon", "enneacontakaitetragon"}},
    {95, {"enneacontapentagon", "enneacontakaipentagon"}},
    {96, {"enneacontahexagon", "enneacontakaihexagon"}},
    {97, {"enneacontaheptagon", "enneacontakaiheptagon"}},
    {98, {"enneacontaoctagon", "enneacontakaioctagon"}},
    {99, {"enneacontaenneagon", "enneacontakaienneagon"}},
    {100, {"hectogon", "hecatontagon"}},
    {1000, {"chiliagon"}},
    {10000, {"myriagon"}},
    {1000000, {"megagon"}}};

PolygonName GetPolygonName(const size_t& n) {
  if (n != 0) {
    auto it = polygon_names_pre.find(n);
    if (it != polygon_names_pre.end()) {
      return it->second;
    } else {
      return {std::to_string(n) + "-gon"};
    }
  } else {
    throw std::out_of_range("n cannot be zero");
    return {""};
  }
}

}  // namespace PolygonName
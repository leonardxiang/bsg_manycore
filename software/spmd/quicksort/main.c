#include "bsg_manycore.h"
#include "bsg_set_tile_x_y.h"

#define NUM_DATA 512

int data[NUM_DATA] __attribute__ ((section (".dram"))) = {
78113, 17198, 14782, 16082, 9277,  85314, 16469, 30084,
52569, 37570, 38166, 67932, 58458, 53102, 75867, 96332,
842,   70077, 62479, 39741, 89951, 35239, 66788, 82916,
37515, 2778,  57651, 22652, 18587, 70651, 70152, 25686,
30002, 89551, 15633, 87965, 88199, 76903, 64265, 84150,
39286, 46186, 39684, 45319, 79187, 24765, 87722, 28434,
22963, 29593, 45248, 58904, 74658, 85106, 69356, 81062,
95151, 14849, 71309, 91866, 27618, 92831, 70993, 82279,
69459, 49125, 65084, 56782, 13365, 52947, 29800, 36505,
44389, 15180, 7282,  8842,  28547, 16757, 88223, 55053,
78651, 11918, 48023, 56872, 65456, 79328, 22877, 77421,
66976, 95917, 76287, 63778, 42452, 34856, 96273, 66728,
27939, 82898, 23122, 33035, 40497, 99457, 10580, 96097,
77039, 18125, 48743, 81845, 19005, 67238, 273,   33233,
65641, 68438, 74165, 46283, 7831,  43678, 75323, 23181,
97566, 89398, 10363, 71153, 48189, 99549, 43076, 64207,
21768, 17813, 95298, 30769, 5252,  40953, 44843, 28675,
86053, 65200, 23326, 12098, 49032, 10877, 42054, 78334,
24958, 17408, 15892, 46539, 77529, 53855, 37170, 66949,
62694, 84726, 37608, 97063, 1273,  86878, 56877, 58631,
74808, 81716, 85051, 77593, 27137, 2514,  12958, 18107,
69421, 48515, 93339, 79173, 43744, 50788, 81895, 50167,
96780, 83471, 10890, 76593, 10634, 60349, 71441, 71063,
78443, 1260,  5639,  98513, 45697, 58424, 93919, 99756,
75990, 10075, 27239, 9225,  63233, 66448, 41648, 93934,
49807, 2790,  91247, 9263,  26127, 53064, 52455, 37274,
91995, 74436, 32544, 44229, 60084, 11431, 26025, 23566,
72647, 94843, 16033, 73780, 81815, 37831, 74525, 22679,
79412, 53942, 40179, 7432,  28444, 70789, 70390, 20765,
73822, 86329, 55946, 89120, 22523, 64467, 41163, 85592,
39180, 47204, 67812, 4571,  2676,  87981, 66139, 2665,
92952, 11268, 53841, 67890, 82685, 80028, 10386, 3746,
49908, 99359, 19322, 34847, 90853, 47484, 18332, 22639,
85879, 12173, 2334,  86230, 16508, 65385, 27103, 84099,
49230, 31059, 39969, 43756, 48062, 10913, 65686, 67907,
81631, 77511, 25472, 1774,  66557, 81673, 10316, 28922,
59837, 36893, 32022, 2347,  61472, 60362, 1486,  92313,
166,   75476, 44272, 73677, 67973, 62160, 78252, 93786,
4101,  69739, 70710, 30313, 16160, 73656, 89928, 5320,
40175, 59055, 76473, 62995, 41856, 39906, 31200, 30741,
14244, 3906,  17403, 39717, 19464, 30302, 13311, 80040,
57594, 57083, 96702, 66238, 87907, 18196, 28452, 47996,
22544, 35808, 27085, 96186, 19619, 68531, 86956, 64498,
57085, 80610, 46467, 67389, 69225, 26929, 8870,  88386,
56471, 3062,  74096, 55261, 35798, 8064,  12270, 98332,
23145, 10384, 5833,  84471, 92980, 80123, 36850, 2998,
31652, 98284, 16159, 91214, 36948, 3682,  46988, 66781,
19136, 54314, 56777, 34878, 61933, 84906, 56563, 82918,
52065, 47415, 29220, 71075, 39498, 4093,  30113, 43433,
45136, 67869, 21036, 5986,  88867, 20127, 41613, 98885,
3178,  61677, 3532,  44181, 75810, 63667, 77713, 28523,
9235,  22837, 64513, 14721, 94931, 25626, 79552, 8319,
19069, 71807, 43160, 68601, 29562, 86803, 23963, 1486,
41701, 97240, 17101, 17868, 44303, 39841, 69142, 4737,
18463, 77554, 36792, 18540, 59552, 34264, 10589, 49596,
36977, 82673, 23666, 45733, 73210, 70394, 51701, 2359,
76012, 98294, 40357, 47529, 25404, 80404, 6820,  77154,
21928, 20807, 69809, 12057, 99611, 63614, 10286, 29264,
48843, 89979, 49130, 47837, 91327, 7789,  34371, 99153,
77359, 31108, 94256, 60328, 24695, 151,   70513, 26519,
15626, 63708, 47553, 38241, 24488, 82810, 76909, 78966,
66993, 18830, 35834, 62145, 67260, 4879,  31055, 16615,
16954, 33938, 49585, 77979, 28119, 82896, 27965, 40909,
3767,  33851, 67335, 86309, 92744, 53379, 21082, 18900
};

#define ANSWER 25247145

int local_lst[NUM_DATA];

void quicksort(int* lst, int n)
{
  if (n == 1)
  {
    return;
  }

  int center = lst[0];
  int front = 0;
  int back = n-1;

  for (int i = 1; i < n; i++)
  {
    int temp = lst[i];
    if (temp >= center)
    {
      local_lst[back] = temp;
      back--;
    }
    else
    {
      local_lst[front] = temp;
      front++;
    }
  } 

  if (back == front)
  {
    local_lst[back] = center; 

    for (int i = 0; i < n; i++) 
    {
      lst[i] = local_lst[i];
    }    
    if (front != 0)
    {
      quicksort(lst, front);
    }
    if (back != n-1)
    {
      quicksort(&(lst[back+1]), n-1-back);
    }
  }
  else
  {
    bsg_fail();
  }
}

int main()
{
  bsg_set_tile_x_y();
  
  if (bsg_x == 0 && bsg_y == 0)
  {
    quicksort(data, NUM_DATA);

    int sum = data[0];
    for (int i = 0; i < NUM_DATA-1; i++)
    {
      sum += data[i+1];

      if (data[i] > data[i+1])
      {
        bsg_fail();
      }
    }
    if (sum == ANSWER)
    {
      bsg_printf("sum: %d, [PASSED]\n", sum);
      bsg_finish();
    }
    else 
    {
      bsg_printf("sum: %d, [FAILED]\n", sum);
      bsg_fail();
    }
  }

  bsg_wait_while(1);
}

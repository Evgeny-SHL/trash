/*

Задача 4
Представитель Tinkoff.ru поехал в Хамовники раздавать карточки новым клиентам. Все встречи проходят в одном месте, проходят подряд (следующая встреча начинается в тот же момент, что и заканчивается предыдущая) и занимают одинаковое количество времени. В конце каждой встречи представитель отмечает в мобильном приложении время окончания встречи, но система логирования дала сбой и на сервер приходит информация только о минутах с начала рабочего дня представителя. Стоит учесть, что 4.(9) минут (фактически 5) могут прийти на сервер и как 4, и как 5. Руководитель группы представителей просит вас рассчитать, за какое минимальное и максимальное время представитель мог проводить встречи этим днем. Обратите внимание, что начало рабочего дня не совпадает с началом первой встречи, так как представитель еще должен доехать до места вручения карточек.

Входные данные
Первая строка содержит число NN – число встреч представителя за этот день (2 \leqslant N \leqslant 10^5)(2⩽N⩽10
5
 ). Вторая строка содержит целочисленную неубывающую последовательность из NN чисел – время в минутах от начала рабочего дня до окончания встреч.
Результат работы
Выведите через пробел с точностью до 10^{-3}10
−3
  два вещественных числа – минимальное и максимальное время, которое могла длиться встреча в этот день. Если система логирования совсем поехала кукухой и при таком расписании встречи не могли проходить одинаковое время, выведите 'kukuha'.

*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  int timeStampsCount = 0;
  std::cin >> timeStampsCount;

  std::vector<double> timeStamps(timeStampsCount);
  for(int i = 0; i < timeStampsCount; ++i) {
    std::cin >> timeStamps[i];
  }

  double min = timeStamps[1] - timeStamps[0] - 1;
  double max = timeStamps[1] - timeStamps[0] + 1;

  for(int i = 0; i < timeStampsCount - 1; ++i) {
    for(int j = i + 1; j < timeStampsCount; ++j) {
      min = std::max(min, (timeStamps[j] - timeStamps[i] - 1) / (j - i));
      max = std::min(max, (timeStamps[j] + 1 - timeStamps[i]) / (j - i));
      if (min > max) {
        std::cout << "kukuha" << std::endl;
          return 0;
      }
    }
  }

  std::cout << std::setprecision(5) << std::fixed << min << " " << max << std::endl;

  return 0;
}

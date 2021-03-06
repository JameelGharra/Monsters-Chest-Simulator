/**
 * RandomGenerator.cpp: generates rolls for the drops of the monsters
 * of the game of RuneScape.
 */

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>
#include <set>
#include "../Parser/Drop.cpp"

class RandomGenerator {
 private:
  inline static RandomGenerator *instance = nullptr;
  std::random_device rd_generator;
  std::mt19937 engine = std::mt19937 (rd_generator ());

  RandomGenerator() = default;
  ~RandomGenerator() {
    delete instance;
  }
  static std::set<const Drop *> roll_table (const std::set<Drop>* const &table)
  {
    std::set<const Drop *> drop_results;
    bool roll_result;
    for (const auto &item : *table)
      {
        roll_result = std::bernoulli_distribution (item.chance) (instance->engine);
        if (roll_result)
          {
            std::uniform_int_distribution quantity_dist (item.min_quantity, item.max_quantity);
            item.recent_quantity = quantity_dist (instance->engine);
            drop_results.insert (&item);
          }
      }
    return std::move(drop_results);
  }
 public:
  static RandomGenerator *get_instance() {
    if(instance == nullptr) {
      instance = new RandomGenerator();
    }
    return instance;
  }
  void operator=(const RandomGenerator &other) = delete;

  std::set<const Drop*> operator()(const std::set<Drop>* const &table) const {
    return roll_table (table);
  }
};
#endif
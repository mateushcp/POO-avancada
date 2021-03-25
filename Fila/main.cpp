#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queue.h"


TEST_CASE("Testa Queue::push()") {
  Queue queue;
  // Insere um único elemento.
  queue.push(-11);
  REQUIRE(queue.count() == 1);
  CHECK(queue.front() == -11);
  CHECK(queue.back() == -11);
  // Insere um segundo elemento.
  queue.push(-22);
  REQUIRE(queue.count() == 2);
  CHECK(queue.front() == -11);
  CHECK(queue.back() == -22);
  // Insere um terceiro elemento.
  queue.push(-33);
  REQUIRE(queue.count() == 3);
  CHECK(queue.front() == -11);
  CHECK(queue.back() == -33);
}

TEST_CASE("Testa Queue::pop()") {
  // Cria uma vila com 3 elementos. 
  Queue queue;
  queue.push(-11);
  queue.push(-22);
  queue.push(-33);

  // Apaga o primeiro elemento.
  queue.pop();
  REQUIRE(queue.count() == 2);
  CHECK(queue.front() == -22);
  CHECK(queue.back() == -33);

  // Apaga o segundo elemento.
  queue.pop();
  REQUIRE(queue.count() == 1);
  CHECK(queue.front() == -33);
  CHECK(queue.back() == -33);

  // Apaga o último elemento.
  queue.pop();
  REQUIRE(queue.count() == 0);
}

TEST_CASE("Testa Queue::count()") {
  Queue queue;
  CHECK(queue.count() == 0);
  queue.push(-11);
  CHECK(queue.count() == 1);
  queue.push(-22);
  CHECK(queue.count() == 2);
  queue.push(-33);
  CHECK(queue.count() == 3);
  queue.pop();
  CHECK(queue.count() == 2);
  queue.pop();
  CHECK(queue.count() == 1);
  queue.pop();
  CHECK(queue.count() == 0);
}

TEST_CASE("Testa se front/back/pop lançam um exceção EmptyException") {
  Queue queue;
  CHECK_THROWS_AS(queue.front(), const Queue::EmptyException&);
  CHECK_THROWS_AS(queue.back(), const Queue::EmptyException&);
  CHECK_THROWS_AS(queue.pop(), const Queue::EmptyException&);
}
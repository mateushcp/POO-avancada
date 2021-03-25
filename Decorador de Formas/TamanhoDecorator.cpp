#include "TamanhoDecorator.hpp"
#include <string>

std::string TamanhoDecorator::desenha(){

    return FormaDecorator::desenha() + "\n- tamanho: " + std::to_string(this->_tamanho);
}

void TamanhoDecorator::setTamanho(int tamanho) {
  this-> _tamanho = tamanho;
}

int TamanhoDecorator::getTamanho() {
  return this->_tamanho;
}

#include "OpacidadeDecorator.hpp"

std::string OpacidadeDecorator::desenha() {
  if(this->_opacidade>=0&&this->_opacidade<=0.33){
    return FormaDecorator::desenha() + "\n- opacidade: " + "baixa";
    } else if (this->_opacidade>=0.34&&this->_opacidade<=0.66){
        return FormaDecorator::desenha() + "\n- opacidade: " + "media";
        } else if(this->_opacidade>=0.67&&this->_opacidade<=1.0) {
            return FormaDecorator::desenha() + "\n- opacidade: " + "alta"; }
                else{return FormaDecorator::desenha();}
}

void OpacidadeDecorator::setOpacidade(double opacidade) {
  this->_opacidade = opacidade;
}

double OpacidadeDecorator::getOpacidade() {
  return this->_opacidade;
}

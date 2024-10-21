#include <iostream>
#include <vector>
#include "Componente.cpp"

// Classe Sala
class Sala {
private:
    std::vector<Sensor*> sensores;
    std::vector<Atuador*> atuadores;
    std::string nome;

public:
    Sala(const std::string& nome, std::vector<Sensor*> sensores, std::vector<Atuador*> atuadores) 
        : nome(nome), sensores(sensores), atuadores(atuadores) {}

    // Método para atualizar todos os sensores e ajustar os atuadores
    void atualizarSensoresAtuadores() {
        int temperatura = -1;
        int umidade = -1;
        int luminosidade = -1;

        std::cout << "Sala: " << nome << "\n";
        
        for (Sensor* sensor : sensores) {
            if (dynamic_cast<Temperatura*>(sensor)) {
                temperatura = dynamic_cast<Temperatura*>(sensor)->getValor();
                dynamic_cast<Temperatura*>(sensor)->mostrarValor();
            } else if (dynamic_cast<Luminosidade*>(sensor)) {
                luminosidade = dynamic_cast<Luminosidade*>(sensor)->getValor();
                dynamic_cast<Luminosidade*>(sensor)->mostrarValor();
            } else if (dynamic_cast<Umidade*>(sensor)) {
                umidade = dynamic_cast<Umidade*>(sensor)->getValor();
                dynamic_cast<Umidade*>(sensor)->mostrarValor();
            }
        }

        for (Atuador* atuador : atuadores) {
            if (dynamic_cast<Ventilador*>(atuador)) {
                dynamic_cast<Ventilador*>(atuador)->ajustarEstado(temperatura);
            } else if (dynamic_cast<Lampada*>(atuador)) {
                dynamic_cast<Lampada*>(atuador)->ajustarEstado(luminosidade);
            } else if (dynamic_cast<Umidificador*>(atuador)) {
                dynamic_cast<Umidificador*>(atuador)->ajustarEstado(umidade);
            } else if (dynamic_cast<Desumidificador*>(atuador)) {
                dynamic_cast<Desumidificador*>(atuador)->ajustarEstado(umidade);
            }
            atuador->mostrarEstado();
        }
    }
};

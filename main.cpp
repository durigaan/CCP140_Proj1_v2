#include <iostream>
#include <vector>
#include <ctime>
#include "Sala.cpp"

int main() {
    // Semente para gerar valores aleatórios
    std::srand(std::time(0));

    // Criando sensores e atuadores para cada sala
    Temperatura temp1, temp2;
    Luminosidade lum1, lum2;
    Umidade umid1, umid2;
    Ventilador vent1, vent2;
    Lampada lamp1, lamp2;
    Umidificador umidificador;
    Desumidificador desumidificador;

    // Criando salas com sensores e atuadores diferentes
    std::vector<Sensor*> sensoresSala1 = {&temp1, &lum1};
    std::vector<Atuador*> atuadoresSala1 = {&vent1, &lamp1};

    std::vector<Sensor*> sensoresSala2 = {&temp2, &umid1};
    std::vector<Atuador*> atuadoresSala2 = {&umidificador, &desumidificador};

    std::vector<Sensor*> sensoresSala3 = {&lum2, &umid2};
    std::vector<Atuador*> atuadoresSala3 = {&vent2, &lamp2};

    Sala sala1("Sala 1", sensoresSala1, atuadoresSala1);
    Sala sala2("Sala 2", sensoresSala2, atuadoresSala2);
    Sala sala3("Sala 3", sensoresSala3, atuadoresSala3);

    // Simulando 1440 atualizações
    for (int i = 1; i <= 1440; ++i) {
        std::cout << "-----------------------------\n";
        std::cout << "Atualização " << i << "\n";

        sala1.atualizarSensoresAtuadores();
        sala2.atualizarSensoresAtuadores();
        sala3.atualizarSensoresAtuadores();

        // Simulando uma pausa entre as atualizações
    }

    return 0;
}

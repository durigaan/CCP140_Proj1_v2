#include <iostream>
#include <cstdlib> // Para números aleatórios
#include <ctime>   // Para seed do rand()

// Classe base Componente
class Componente {
protected:
    bool ligado;
    bool conectado;
    int valor;
    std::string nome;

public:
    Componente() : ligado(false), conectado(false), valor(0) {}

    void ligar() { ligado = true; }
    void desligar() { ligado = false; }
    bool isLigado() const { return ligado; }
    bool conectar() { return conectado = true; }
    void desconectar() { conectado = false; }

    virtual int getValor() const { return valor; }
};

// Classe Sensor (herda de Componente)
class Sensor : public Componente {
public:
    virtual int getValor() = 0; // Função virtual pura
};

// Subclasse Temperatura (herda de Sensor)
class Temperatura : public Sensor {
public:
    int getValor() override {
        valor = std::rand() % 36 + 15;  // Gera um valor aleatório entre 15 e 50°C
        return valor;
    }

    float getFahrenheit() {
        return (getValor() * 9.0 / 5.0) + 32.0;
    }

    float getKelvin() {
        return getValor() + 273.15;
    }

    void mostrarValor() {
        std::cout << "Sensor: Temperatura - Valor: " << valor << " °C, " 
                  << getFahrenheit() << " °F, " << getKelvin() << " K\n";
    }
};

// Subclasse Luminosidade (herda de Sensor)
class Luminosidade : public Sensor {
public:
    int getValor() override {
        valor = std::rand() % 101;  // Gera um valor aleatório entre 0 e 100%
        return valor;
    }

    void mostrarValor() {
        std::cout << "Sensor: Luminosidade - Valor: " << valor << "%\n";
    }
};

// Subclasse Umidade (herda de Sensor)
class Umidade : public Sensor {
public:
    int getValor() override {
        valor = std::rand() % 101;  // Gera um valor aleatório entre 0 e 100%
        return valor;
    }

    void mostrarValor() {
        std::cout << "Sensor: Umidade - Valor: " << valor << "%\n";
    }
};

// Classe Atuador (herda de Componente)
class Atuador : public Componente {
public:
    virtual void setValor(int v) = 0; // Função virtual pura

    virtual void mostrarEstado() const {
        std::cout << "Estado: " << (ligado ? "On" : "Off") << "\n";
    }
};

// Subclasse Ventilador (herda de Atuador)
class Ventilador : public Atuador {
public:
    void setValor(int v) override {
        valor = v;
    }

    void ajustarEstado(int tempAtual) {
        if (tempAtual > 30) {
            ligar();
        } else {
            desligar();
        }
    }

    void mostrarEstado() const override {
        std::cout << "Atuador: Ventilador - ";
        Atuador::mostrarEstado();
    }
};

// Subclasse Umidificador (herda de Atuador)
class Umidificador : public Atuador {
public:
    void setValor(int v) override {
        valor = v;
    }

    void ajustarEstado(int umidadeAtual) {
        if (umidadeAtual < 30) {
            ligar();
        } else {
            desligar();
        }
    }

    void mostrarEstado() const override {
        std::cout << "Atuador: Umidificador - ";
        Atuador::mostrarEstado();
    }
};

// Subclasse Desumidificador (herda de Atuador)
class Desumidificador : public Atuador {
public:
    void setValor(int v) override {
        valor = v;
    }

    void ajustarEstado(int umidadeAtual) {
        if (umidadeAtual > 70) {
            ligar();
        } else {
            desligar();
        }
    }

    void mostrarEstado() const override {
        std::cout << "Atuador: Desumidificador - ";
        Atuador::mostrarEstado();
    }
};

// Subclasse Lampada (herda de Atuador)
class Lampada : public Atuador {
public:
    void setValor(int v) override {
        valor = v;
    }

    void ajustarEstado(int luminosidadeAtual) {
        if (luminosidadeAtual < 40) {
            ligar();
        } else {
            desligar();
        }
    }

    void mostrarEstado() const override {
        std::cout << "Atuador: Lâmpada - ";
        Atuador::mostrarEstado();
    }
};

#pragma once
#include "identidade.hpp"
#include <map>
#include <set>

struct Medicao {
    double valor;
    std::string unidade;
};

// Fornecido: T varia o item, preservando a chave e o contrato do catálogo.
template<typename T>
class Catalogo {
    std::map<IdSensor, T> itens_;
public:
    bool inserir(const IdSensor& id, const T& item) {
        auto resultado = itens_.emplace(id, item);
        return resultado.second;
    }

    const T* buscar(const IdSensor& id) const {
        auto resultado = itens_.find(id);
        if (resultado == itens_.end()) return nullptr;
        return &resultado->second;
    }

    bool remover(const IdSensor& id) {
        // TODO 02: true somente quando uma entrada for removida.
        (void)id;
        return false;
    }

    std::size_t quantidade() const { return itens_.size(); }

    std::set<IdSensor> ids() const {
        std::set<IdSensor> resultado;
        for (const auto& entrada : itens_) resultado.insert(entrada.first);
        return resultado;
    }
};
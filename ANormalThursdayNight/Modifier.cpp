//
// Created by Zachary James Gospe on 10/21/16.
//

#include "Modifier.h"

Modifier::Modifier(size_t place, std::string word) :
    name(word),
    type(place),
    damPlus(0),
    acPlus(0),
    usePlus(0),
    damMult(1),
    acMult(1)
{
}

Modifier::Modifier() :
        name(""),
        type(1),
        damPlus(0),
        acPlus(0),
        usePlus(0),
        damMult(1),
        acMult(1)
{
}

void Modifier::setName(std::string string) {
    name = string;
}

void Modifier::setType(size_t val) {
    type = val;
}

void Modifier::setDamPlus(int val) {
    damPlus = val;
}

void Modifier::setACPlus(int val) {
    acPlus = val;
}

void Modifier::setUsePlus(int val) {
    usePlus = val;
}

void Modifier::setDamMult(double val) {
    damMult = val;
}

void Modifier::setACMult(double val) {
    acMult = val;
}

std::string Modifier::getName() {
    return name;
}

size_t Modifier::getType() {
    return type;
}

int Modifier::getDamPlus() {
    return damPlus;
}

int Modifier::getACPlus() {
    return acPlus;
}

int Modifier::getUsePlus() {
    return usePlus;
}

double Modifier::getDamMult() {
    return damMult;
}

double Modifier::getACMult() {
    return acMult;
}

Modifier::Modifier(size_t t, std::string nom, int dP, int aP, int uP, double dM, double aM):
                    name(nom), type(t),
                    damPlus(dP), acPlus(aP),
                    usePlus(uP), damMult(dM),
                    acMult(aM)
{
    //nothing left to do
}




#!/bin/bash
echo "Probando 16 combinaciones de longitud 1"
echo {{0..9},{A..F}}
echo "-----------------------------------------------------------------------------------------------------"

echo "Probando 256 combinaciones de longitud 2"
echo {{0..9},{A..F}}{{0..9},{A..F}}
echo "-----------------------------------------------------------------------------------------------------"

echo "Probando 4096 combinaciones de longitud 3"
echo {{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}}
echo "-----------------------------------------------------------------------------------------------------"

echo "Probando 65536 combinaciones de longitud 4"
echo {{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}}
echo "-----------------------------------------------------------------------------------------------------"


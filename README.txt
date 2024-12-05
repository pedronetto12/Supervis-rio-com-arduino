# Documentação do Projeto

Este repositório contém os arquivos necessários para o funcionamento do projeto, organizados em diferentes pastas para facilitar o entendimento e uso.

---

## Estrutura das Pastas

### 📂 `projeto`
Contém os principais arquivos do projeto:
- **Código Arduino:** Arquivo com o programa utilizado no microcontrolador.
- **Programa do Elipse E3:** Arquivo do projeto desenvolvido no Elipse E3 para supervisão e controle.

### 📂 `bibliotecas`
Inclui todas as bibliotecas necessárias para o projeto:
- **Biblioteca Modbus (Arduino):** 
  - Implementa a comunicação Modbus no Arduino.
  - Contém um exemplo com a declaração de todos os registradores das respectivas portas do controlador.
- **Biblioteca do Elipse E3:** 
  - Fornece suporte à comunicação com o software Elipse E3.

---

## Como Utilizar

1. **Preparar o Ambiente:**
   - Certifique-se de que todas as bibliotecas necessárias estejam instaladas corretamente.
   - Configure o software Elipse E3 com o arquivo de projeto fornecido.

2. **Carregar o Código no Arduino:**
   - Use o arquivo localizado na pasta `projeto` para carregar o programa no microcontrolador.

3. **Executar o Elipse E3:**
   - Importe o projeto do Elipse E3 e configure os parâmetros de comunicação com o Arduino.

4. **Iniciar o Sistema:**
   - Ligue o microcontrolador e abra o software Elipse E3 para visualizar e controlar o sistema.


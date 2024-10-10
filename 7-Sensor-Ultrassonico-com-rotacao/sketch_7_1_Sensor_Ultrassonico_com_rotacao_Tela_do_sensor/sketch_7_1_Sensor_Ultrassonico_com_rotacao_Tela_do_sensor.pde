import processing.serial.*; // Importa a biblioteca para comunicação serial
import java.awt.event.KeyEvent; // Importa a biblioteca para leitura de dados da porta serial
import java.io.IOException;

Serial myPort; // Define o objeto Serial para comunicação
// Define variáveis
String angle = ""; // Variável para armazenar o ângulo
String distance = ""; // Variável para armazenar a distância
String data = ""; // Variável para armazenar os dados recebidos
String noObject; // Variável para indicar se há ou não objeto
float pixsDistance; // Variável para armazenar a distância em pixels
int iAngle, iDistance; // Variáveis para armazenar o ângulo e a distância em inteiro
int index1 = 0; // Índices para manipulação de dados recebidos
int index2 = 0;
PFont orcFont;

void setup() {
  size(1200, 700); // Define o tamanho da tela (resolução)
  smooth(); // Ativa o suavizado
  myPort = new Serial(this, "COM4", 9600); // Inicia a comunicação serial
  myPort.bufferUntil('.'); // Define para ler dados até o caractere '.'
}

void draw() {
  fill(98, 245, 31); // Define a cor verde
  noStroke(); // Sem contorno para formas
  fill(0, 4); // Define a cor com leve opacidade para o efeito de desfoque de movimento
  rect(0, 0, width, height - height * 0.065); // Desenha um retângulo para desfoque

  fill(98, 245, 31); // Define a cor verde
  // Chama as funções para desenhar o radar
  drawRadar();
  drawLine();
  drawObject();
  drawText();
}

void serialEvent(Serial myPort) { // Lê dados da porta serial
  data = myPort.readStringUntil('.'); // Lê dados até o caractere '.'
  data = data.substring(0, data.length() - 1); // Remove o último caractere ('.')

  index1 = data.indexOf(","); // Encontra a posição da vírgula
  angle = data.substring(0, index1); // Extrai o ângulo dos dados recebidos
  distance = data.substring(index1 + 1, data.length()); // Extrai a distância dos dados recebidos

  // Converte as variáveis de String para Inteiro
  iAngle = int(angle);
  iDistance = int(distance);
}

void drawRadar() {
  pushMatrix();
  translate(width / 2, height - height * 0.074); // Movimenta a origem do desenho
  noFill();
  strokeWeight(2); // Define a espessura da linha
  stroke(98, 245, 31); // Define a cor verde para o radar
  // Desenha os arcos do radar
  arc(0, 0, (width - width * 0.0625), (width - width * 0.0625), PI, TWO_PI);
  arc(0, 0, (width - width * 0.27), (width - width * 0.27), PI, TWO_PI);
  arc(0, 0, (width - width * 0.479), (width - width * 0.479), PI, TWO_PI);
  arc(0, 0, (width - width * 0.687), (width - width * 0.687), PI, TWO_PI);
  // Desenha as linhas de ângulo
  line(-width / 2, 0, width / 2, 0);
  line(0, 0, (-width / 2) * cos(radians(30)), (-width / 2) * sin(radians(30)));
  line(0, 0, (-width / 2) * cos(radians(60)), (-width / 2) * sin(radians(60)));
  line(0, 0, (-width / 2) * cos(radians(90)), (-width / 2) * sin(radians(90)));
  line(0, 0, (-width / 2) * cos(radians(120)), (-width / 2) * sin(radians(120)));
  line(0, 0, (-width / 2) * cos(radians(150)), (-width / 2) * sin(radians(150)));
  popMatrix();
}

void drawObject() {
  pushMatrix();
  translate(width / 2, height - height * 0.074); // Movimenta a origem do desenho
  strokeWeight(9);
  stroke(255, 10, 10); // Define a cor vermelha para o objeto
  pixsDistance = iDistance * ((height - height * 0.1666) * 0.025); // Converte a distância de cm para pixels
  if (iDistance < 40) { // Limita a distância máxima a 40 cm
    line(pixsDistance * cos(radians(iAngle)), -pixsDistance * sin(radians(iAngle)),
      (width - width * 0.505) * cos(radians(iAngle)), -(width - width * 0.505) * sin(radians(iAngle)));
  }
  popMatrix();
}

void drawLine() {
  pushMatrix();
  strokeWeight(9);
  stroke(30, 250, 60); // Define a cor verde para a linha
  translate(width / 2, height - height * 0.074); // Movimenta a origem do desenho
  line(0, 0, (height - height * 0.12) * cos(radians(iAngle)), -(height - height * 0.12) * sin(radians(iAngle))); // Desenha a linha conforme o ângulo
  popMatrix();
}

void drawText() { // Desenha o texto na tela
  pushMatrix();
  if (iDistance > 40) {
    noObject = "Out of Range"; // Fora do alcance
  } else {
    noObject = "In Range"; // Dentro do alcance
  }
  fill(0, 0, 0);
  noStroke();
  rect(0, height - height * 0.0648, width, height); // Desenha retângulo preto para o texto
  fill(98, 245, 31);
  textSize(25);
  text("10cm", width - width * 0.3854, height - height * 0.0833);
  text("20cm", width - width * 0.281, height - height * 0.0833);
  text("30cm", width - width * 0.177, height - height * 0.0833);
  text("40cm", width - width * 0.0729, height - height * 0.0833);
  textSize(40);
  text("SciCraft ", width - width * 0.875, height - height * 0.0277);
  text("Angle: " + iAngle + " °", width - width * 0.48, height - height * 0.0277);
  text("Distance:   ", width - width * 0.30, height - height * 0.0277);
  if (iDistance < 40) {
    text("        " + iDistance + " cm", width - width * 0.225, height - height * 0.0277);
  }
  popMatrix();
}

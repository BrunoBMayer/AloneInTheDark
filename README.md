# 👻ALONE IN THE DARK
Alone in the Dark é um jogo simples de labirinto às cegas. Desenvolvido como projeto para a disciplina de PIF, nesse jogo você terá que encontrar a saída do labirinto com uma visão limitada e um tempo de 5 minutos. O título é uma homenagem à clássica franquia de jogos "Alone in the Dark".

# 📖 LORE
Você é Jonas, um autor de ficção científica, que misteriosamente acorda dentro de sua própria obra "Alone in the dark". Em sua obra, o protagonista acorda sem explicações dentro de uma caverna e precisa encontrar a saída para entender como ele foi parar ali, quem o colocou e o motivo.

# 💻COMO EXECUTAR O JOGO
O jogo rodará apenas em um terminal linux. Caso não tenha uma máquina com linux, use o replit.

- 1 - Clone o repositório: 'https://github.com/BrunoBMayer/AloneInTheDark.git'
- 2 - Compile o programa: 'make'
- 3 - Execute o programa: './alone'
- 4 - Fuja do labirinto a tempo!! 😈

# 🎮COMO O JOGO FUNCIONA
O jogador utilizará as teclas "w-a-s-d" para se locomover pelo labirinto. O tempo limite é de 5 minutos. Seu tempo será salvo em um ranking local de pontuações.

# 👽MEMBROS

---

## Clone o repositório

<div style="display: flex; align-items: center;">
  <pre style="margin: 0; padding: 0.5em; background: #f0f0f0; border: 1px solid #ddd; border-radius: 5px;">
    <code id="repo-url">https://github.com/BrunoBMayer/AloneInTheDark.git</code>
  </pre>
  <button onclick="copyToClipboard('repo-url')">Copiar</button>
</div>

## Compile o programa

<div style="display: flex; align-items: center;">
  <pre style="margin: 0; padding: 0.5em; background: #f0f0f0; border: 1px solid #ddd; border-radius: 5px;">
    <code id="make-command">make</code>
  </pre>
  <button onclick="copyToClipboard('make-command')">Copiar</button>
</div>

## Execute o programa

<div style="display: flex; align-items: center;">
  <pre style="margin: 0; padding: 0.5em; background: #f0f0f0; border: 1px solid #ddd; border-radius: 5px;">
    <code id="run-command">./alone</code>
  </pre>
  <button onclick="copyToClipboard('run-command')">Copiar</button>
</div>

<script>
  function copyToClipboard(elementId) {
    const text = document.getElementById(elementId).innerText;
    navigator.clipboard.writeText(text).then(function() {
      alert('Texto copiado!');
    }, function(err) {
      alert('Erro ao copiar o texto');
    });
  }
</script>

let game = null;
let lastTime = null;

const tick = () => {
    let delta = lastTime != null ? new Date().getTime() - lastTime : 0;

    if (game == null) {
        let level = document.querySelector('section').id.replace('level', '');
        game = new Game(level);
    }

    lastTime = new Date().getTime();
    let isRunning = game.tick(delta/1000);

    if (isRunning) {
        window.requestAnimationFrame(tick);
    }
}

window.requestAnimationFrame(tick);
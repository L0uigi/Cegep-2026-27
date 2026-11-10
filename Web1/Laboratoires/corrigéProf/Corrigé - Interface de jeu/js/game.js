let gameState = 0;
let game = null;
let previousTimestamp = 0;

document.addEventListener("DOMContentLoaded", function() {
    game = new SplashScreen();

    window.addEventListener("keydown", (event) => game.handleKey(event, true));
    window.addEventListener("keyup", (event) => game.handleKey(event, false));

    window.requestAnimationFrame(tick);
});

const tick = timestamp => {
    if (!previousTimestamp) previousTimestamp = timestamp;
    const delta = timestamp - previousTimestamp;
    previousTimestamp = timestamp;

    game = game.tick(delta) ?? game;
    window.requestAnimationFrame(tick);
}
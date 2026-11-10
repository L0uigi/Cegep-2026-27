class GameOverScreen {
    constructor(score) {
        this.restartGame = false;
        document.getElementById("final-score").textContent = "Pointage " + score;
        document.getElementById("splash-screen").style.display = "none";
        document.getElementById("game-screen").style.display = "none";
        document.getElementById("game-over-screen").style.display = "block";
    }

    handleKey(event, isKeyDown) {
        if (event.key == "Enter" && !isKeyDown) {
            this.restartGame = true;
        }
    }

    tick(delta) {
        return this.restartGame ? new SplashScreen() : null;
    }
}
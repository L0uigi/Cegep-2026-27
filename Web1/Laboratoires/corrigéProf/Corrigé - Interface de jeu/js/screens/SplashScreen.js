class SplashScreen {
    constructor() {
        this.startGame = false;
        document.getElementById("splash-screen").style.display = "block";
        document.getElementById("game-screen").style.display = "none";
        document.getElementById("game-over-screen").style.display = "none";
    }

    handleKey(event, isKeyDown) {
        if (event.key == "Enter" && !isKeyDown) {
            this.startGame = true;
        }
    }

    tick(delta) {

        return this.startGame ? new GameScreen() : null;
    }
}
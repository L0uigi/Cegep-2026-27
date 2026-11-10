class GameScreen {
    constructor() {
        document.getElementById("splash-screen").style.display = "none";
        document.getElementById("game-screen").style.display = "block";
        document.getElementById("game-over-screen").style.display = "none";

        this.spriteList = [];
        this.timeElapsed = 0;
        this.meteorDelay = 2000;
        this.meteorTimer = 0;

        this.playerSprite = new PlayerSprite();
        this.spriteList.push(this.playerSprite);
    }

    handleKey(event, isKeyDown) {
        this.playerSprite.handleKey(event, isKeyDown);
    }

    tick(delta) {
        this.timeElapsed += delta;
        let score = Math.floor(this.timeElapsed / 10);
        document.querySelector("#score").textContent = "Pointage " + score;

        let dead = false;

        this.meteorTimer += delta;
        if (this.meteorTimer >= this.meteorDelay) {
            this.meteorTimer = 0;
            this.meteorDelay *= 0.95;
            if (this.meteorDelay < 250) this.meteorDelay = 250;

            const meteor = new MeteorSprite(this.playerSprite);
            this.spriteList.push(meteor);
        }

        for (let i = 0; i < this.spriteList.length; i++) {
            const sprite = this.spriteList[i];
            const info = sprite.tick(delta);

            if (!info[0]) {
                this.spriteList.splice(i, 1);
                i--;
            }

            if (info[1]) {
                dead = true;
                document.querySelectorAll("#game-screen div").forEach((node) => node.remove());
            }
        }

        return dead ? new GameOverScreen(score) : null;
    }
}

class MeteorSprite {
    constructor(playerSprite) {
        this.playerSprite = playerSprite;
        this.node = document.createElement("div");
        this.node.id = "projectile";
        this.gameScreen = document.getElementById("game-screen");
        this.gameScreen.append(this.node);

        this.meteorWidth = this.node.offsetWidth;
        this.meteorHeight = this.node.offsetHeight;

        let rnd = Math.random();
        let rotation = null;

        if (rnd < 0.25) {
            this.x = -this.meteorWidth;
            this.y = Math.random() * (600 - this.meteorHeight);
            this.vx = 0.1 + Math.random() * 0.2;
            this.vy = (Math.random() - 0.5) * 0.2;
        } else if (rnd < 0.5) {
            this.x = 900;
            this.y = Math.random() * (600 - this.meteorHeight);
            this.vx = - (0.1 + Math.random() * 0.2);
            this.vy = (Math.random() - 0.5) * 0.2;
        } else if (rnd < 0.75) {
            this.x = Math.random() * (900 - this.meteorWidth);
            this.y = -this.meteorHeight;
            this.vx = (Math.random() - 0.5) * 0.2;
            this.vy = 0.1 + Math.random() * 0.2;
        } else {
            this.x = Math.random() * (900 - this.meteorWidth);
            this.y = 600;
            this.vx = (Math.random() - 0.5) * 0.2;
            this.vy = - (0.1 + Math.random() * 0.2);
        }

        rotation = Math.atan2(this.vy, this.vx) * 180 / Math.PI + 90;
        this.node.style.rotate = rotation + "deg";
    }

    tick(delta) {
        let alive = true;
        const speed = 0.6;
        this.x += this.vx * speed * delta;
        this.y += this.vy * speed * delta;

        this.node.style.top = this.y + "px";
        this.node.style.left = this.x + "px";

        if (this.x < -this.meteorWidth || this.x > 900 || this.y < -this.meteorHeight || this.y > 600) {
            this.node.remove();
            alive = false;
        }

        let hasHit = false;
        const playerRect = this.playerSprite.node.getBoundingClientRect();
        const meteorRect = this.node.getBoundingClientRect();
        let distance = Math.hypot((this.x + this.meteorWidth/2) - (this.playerSprite.x + this.playerSprite.playerWidth/2),
                                  (this.y + this.meteorHeight/2) - (this.playerSprite.y + this.playerSprite.playerHeight/2));

        if (distance < (this.meteorWidth + this.playerSprite.playerWidth)/2 * 0.6) {
            hasHit = true;
            this.node.remove();
        }

        return [alive, hasHit];
    }
}

class PlayerSprite {
    constructor() {
        this.node = document.createElement("div");
        this.node.id = "player";
        this.gameScreen = document.getElementById("game-screen");
        this.gameScreen.append(this.node);

        this.playerWidth = this.node.offsetWidth;
        this.playerHeight = this.node.offsetHeight;

        this.x = this.gameScreen.offsetWidth/2 - this.playerWidth/2;
        this.y = this.gameScreen.offsetHeight/2 - this.playerHeight/2;

        this.topIsPressed = false;
        this.bottomIsPressed = false;
        this.leftIsPressed = false;
        this.rightIsPressed = false;
    }

    handleKey(event, isKeyDown) {
        if (event.key == "ArrowUp") {
            this.topIsPressed = isKeyDown;
            event.preventDefault();
        } else if (event.key == "ArrowDown") {
            this.bottomIsPressed = isKeyDown;
            event.preventDefault();
        } else if (event.key == "ArrowLeft") {
            this.leftIsPressed = isKeyDown;
            event.preventDefault();
        } else if (event.key == "ArrowRight") {
            this.rightIsPressed = isKeyDown;
            event.preventDefault();
        }
    }

    tick(delta) {
        const speed = 0.3;

        if (this.topIsPressed) this.y -= speed * delta;
        if (this.bottomIsPressed) this.y += speed * delta;
        if (this.leftIsPressed) this.x -= speed * delta;
        if (this.rightIsPressed) this.x += speed * delta;

        if (this.x < 0) this.x = 0;
        if (this.x > 900 - this.playerWidth) this.x = 900 - this.playerWidth;
        if (this.y < 0) this.y = 0;
        if (this.y > 600 - this.playerHeight) this.y = 600 - this.playerHeight;

        this.node.style.top = this.y + "px";
        this.node.style.left = this.x + "px";

        return [true, false];
    }
}
class Game {
    constructor(level) {
        this.level = level;

        this.mouse = null;
        this.gravity = 3;
        this.mazeDivs = [];

        this.mazeSize = 10;
        this.gameSize = document.querySelector('section').offsetWidth;
        this.cellSize = this.gameSize / this.mazeSize;
        this.levelContainer = document.querySelector('#level' + level);

        this.createLevel();
        this.gameState = 0;
    }

    createMaze(walls) {
        walls.forEach((wall, index) => {
            if (wall > 0 && wall < 3) {
                let wallDiv = document.createElement('div');
                wallDiv.classList.add(wall == 1 ? 'wall' : 'spike');
                this.levelContainer.appendChild(wallDiv);

                wallDiv.style.left = index % this.mazeSize * this.cellSize + 'px';
                wallDiv.style.top = Math.floor(index / this.mazeSize) * this.cellSize + 'px';
                wallDiv.style.width = this.cellSize + 'px';
                wallDiv.style.height = this.cellSize + 'px';

                this.mazeDivs.push(wallDiv);
            }
            else if (wall == 3) {
                let mouseDiv = document.createElement('div');
                mouseDiv.classList.add('mouse');
                this.levelContainer.appendChild(mouseDiv);

                let tiledImage = new TiledImage('img/mouse.png', 4, 3, 50, true, 0.35, mouseDiv);
                tiledImage.setFullImageLoop(12);

                this.mouse = {
                    x: index % this.mazeSize * this.cellSize,
                    y: Math.floor(index / this.mazeSize) * this.cellSize + this.cellSize/3,
                    x_speed: 100,
                    y_speed: 0,
                    div : mouseDiv,
                    tiledImage,
                }
                this.mouse.x_previous = this.mouse.x;
                this.mouse.y_previous = this.mouse.y;
            }
            else if (wall == 4) {
                let cheeseDiv = document.createElement('div');
                cheeseDiv.classList.add('cheese');
                this.levelContainer.appendChild(cheeseDiv);

                cheeseDiv.style.left = index % this.mazeSize * this.cellSize + 'px';
                cheeseDiv.style.top = Math.floor(index / this.mazeSize) * this.cellSize + 'px';
                cheeseDiv.style.width = this.cellSize + 'px';
                cheeseDiv.style.height = this.cellSize + 'px';

                this.mazeDivs.push(cheeseDiv);
            }
            else if (wall == 5) {
                let jumpDiv = document.createElement('div');
                jumpDiv.classList.add('jump');
                this.levelContainer.appendChild(jumpDiv);

                jumpDiv.style.left = index % this.mazeSize * this.cellSize + 'px';
                jumpDiv.style.top = Math.floor(index / this.mazeSize) * this.cellSize + 'px';
                jumpDiv.style.width = this.cellSize + 'px';
                jumpDiv.style.height = this.cellSize + 'px';

                this.mazeDivs.push(jumpDiv);
            }
        })

        document.querySelectorAll("main > div").forEach(div => {
            if (div.classList.contains('wall') || div.classList.contains('jump')) {
                this.mazeDivs.push(div);
            }
        });
    }

    createLevel() {
        let infoText = "";
        this.limits = {lines : 0, columns: 0, walls: 0};

        if (this.level == 1) {
            this.limits = {lines : 1, columns: 4, walls: 1, jumps : 0, divs : 4, ops : ["grid-template-columns", "grid-template-rows"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
                0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 2) {
            this.limits = {lines : 4, columns: 3, walls: 1, jumps : 1, divs : 9, ops : ["grid-template-columns", "grid-template-rows", , "grid-row-start", "grid-row-end", "grid-column-start", "grid-column-end"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
                3, 0, 0, 0, 0, 0, 0, 2, 2, 2,
                1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 3) {
            this.limits = {lines : 3, columns: 3, walls: 3, jumps : 0, divs : 9, ops : ["grid-template-columns", "grid-template-rows"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                2, 2, 2, 0, 0, 0, 0, 2, 2, 2,
                0, 0, 2, 0, 0, 0, 0, 2, 2, 2,
                0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 2, 0, 0, 0, 0, 0, 4, 0,
                0, 0, 2, 1, 1, 1, 1, 1, 1, 1,
            ]);
        }
        else if (this.level == 4) {
            this.limits = {lines : 4, columns: 5, walls: 1, jumps : 0, divs : 1, ops : ["grid-template-columns (fr)", "grid-template-rows (fr)", "grid-row-start", "grid-row-end", "grid-column-start", "grid-column-end"]};
            this.createMaze([
                0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 2, 2, 2, 2, 2, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                0, 4, 0, 0, 0, 1, 0, 0, 0, 0,
                0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 5) {
            this.limits = {lines : 8, columns: 8, walls: 1, jumps : 0, divs : 1, ops : ["grid-template-columns (fr)", "grid-template-rows (fr)", "grid-area"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 1, 1, 0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 2, 2, 2, 0, 0, 1,
                0, 0, 0, 0, 2, 2, 2, 0, 0, 1,
                0, 0, 0, 0, 2, 2, 2, 0, 0, 1,
                0, 0, 0, 0, 2, 2, 2, 0, 0, 1,
                0, 4, 0, 0, 0, 0, 0, 0, 0, 1,
                0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            ]);
        }
        else if (this.level == 6) {
            this.limits = {lines : 3, columns: 3, walls: 2, jumps : 0, divs : 2, ops : ["grid-template-columns (px)", "grid-template-rows (px)", "grid-area"]};
            this.createMaze([
                0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 2, 2, 2, 2, 0, 0, 2, 0, 0,
                0, 0, 0, 0, 2, 0, 0, 2, 0, 0,
                0, 0, 0, 0, 2, 0, 0, 2, 0, 0,
                0, 0, 0, 0, 2, 0, 0, 2, 0, 0,
                0, 1, 2, 2, 2, 0, 0, 2, 2, 1,
                0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
                0, 1, 0, 0, 0, 0, 0, 0, 4, 1,
                0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            ]);
        }
        else if (this.level == 7) {
            this.limits = {lines : 2, columns: 2, walls: 4, jumps : 0, divs : 4, ops : ["grid-template-columns (fr)", "grid-template-rows (fr)", "row-gap", "column-gap"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 4, 0,
                3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 2, 2, 0, 0, 5, 0, 0, 2, 2,
                0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 8) {
            this.limits = {lines : 8, columns: 8, walls: 0, jumps : 1, divs : 1, ops : ["grid-template-columns", "grid-template-rows", "grid-area"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 2, 2, 2, 0,
                0, 0, 0, 0, 0, 0, 0, 4, 2, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
                0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 9) {
            this.limits = {lines : 10, columns: 10, walls: 1, jumps : 2, divs : 3, ops : ["grid-template-columns", "grid-template-rows", "grid-area"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 1, 1, 1, 1, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 3, 0, 0, 0, 0, 2, 2, 2, 2,
                0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 10) {
            this.limits = {lines : 10, columns: 10, walls: 1, jumps : 2, divs : 3, ops : ["grid-template-columns", "grid-template-rows", "grid-area"]};
            this.createMaze([
                1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 1, 0, 0, 3, 0, 1,
                1, 0, 0, 4, 1, 0, 0, 1, 1, 1,
                1, 0, 0, 1, 1, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 2, 2, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 2, 0, 0, 1,
                1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
                0, 0, 2, 2, 1, 1, 1, 1, 1, 1,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 11) {
            this.limits = {lines : 10, columns: 10, walls: "-", jumps : "-", divs : "-", ops : ["Bonne chance !"]};
            this.createMaze([
                1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
                1, 0, 0, 1, 1, 1, 0, 0, 0, 1,
                1, 0, 0, 0, 2, 0, 0, 2, 2, 2,
                1, 1, 0, 0, 2, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                3, 0, 0, 0, 1, 1, 1, 0, 0, 0,
                2, 2, 2, 2, 4, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 12) {
            this.limits = {lines : 0, columns: 0, walls: "-", jumps : "-", divs : "-", ops : ["Ce niveau n'est pas fait. Modifier le fichier game.js pour créer le vôtre!"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 2, 2, 2, 2, 4, 2, 0, 0,
                0, 0, 2, 1, 1, 1, 1, 2, 0, 0,
                0, 0, 2, 1, 3, 0, 1, 2, 0, 0,
                0, 0, 2, 1, 1, 1, 1, 2, 0, 0,
                0, 0, 2, 2, 2, 2, 2, 2, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 13) {
            this.limits = {lines : 10, columns: 10, walls: 0, jumps : "3", divs : "3", ops: ["Fait par Julien (H2026)"]};
            this.createMaze([
                1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                1, 0, 0, 0, 2, 2, 0, 0, 0, 0,
                1, 0, 0, 2, 2, 2, 2, 4, 2, 0,
                1, 0, 1, 1, 1, 1, 1, 2, 2, 0,
                1, 0, 1, 1, 0, 0, 1, 2, 0, 0,
                1, 0, 1, 1, 1, 1, 1, 2, 0, 0,
                1, 0, 1, 2, 2, 2, 2, 2, 0, 0,
                1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                1, 3, 1, 0, 0, 0, 0, 0, 0, 0,
                1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 14) {
            this.limits = {lines : 10, columns: 10, walls: "1", jumps : "1", divs : "2", ops : ["Par Maxime (H2026)"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                2, 2, 2, 2, 0, 2, 0, 2, 2, 2,
                2, 3, 0, 0, 0, 2, 0, 0, 0, 4,
                0, 1, 1, 1, 1, 2, 0, 1, 1, 1,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
        else if (this.level == 15) {
            this.limits = {lines : 10, columns: 10, walls: "1", jumps : "1", divs : "2", ops : ["Par Nathan (H2026)"]};
            this.createMaze([
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 4, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            ]);
        }
         else if (this.level == 16) {
            this.limits = {lines : 10, columns: 10, walls: 2, jumps : 1, divs : 3, ops : ["Le mur est un peu énervant. Par Lucca (H2026)"]};
            this.createMaze([
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                3, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 0, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 4, 0, 0,
                0, 0, 0, 0, 0, 2, 1, 1, 1, 0,
            ]);
        }

        infoText = "Nb lignes : <span>" + this.limits.lines +
                    "</span> - Nb colonnes : <span>" + this.limits.columns +
                    "</span> - Nb divs : <span>" + this.limits.divs +
                    "</span> - Nb murs : <span>" + this.limits.walls +
                    "</span> - Nb sauts : <span>" + this.limits.jumps +
                    "</span> - Dimension du jeu : <span>" + this.gameSize + "px/" + this.gameSize + "px " +
                    "</span><div style='margin-top: 5px;'><span>" + this.limits.ops.join(", ") + "</span></div>";

        document.querySelector(".info").innerHTML = infoText;
        document.querySelector("h1").innerText = "Niveau " + this.level;

        let startButton = document.createElement('button');
        startButton.innerText = "Démarrer";
        startButton.addEventListener('click', () => {
            this.gameState = 1;
            startButton.remove();
        })
        this.levelContainer.append(startButton);
    }

    isColliding(div1, div2, horizontalTolerance = 0, verticalTolerance = 0) {
        let rect1 = div1.getBoundingClientRect();
        let rect2 = div2.getBoundingClientRect();

        return rect1.left + this.cellSize * horizontalTolerance < rect2.right &&
             rect1.right - this.cellSize * horizontalTolerance > rect2.left &&
             rect1.top + this.cellSize * verticalTolerance < rect2.bottom &&
             rect1.bottom - this.cellSize * verticalTolerance > rect2.top;
    }

    tick(delta) {
        let isRunning = true;

        if (this.gameState == 0) {
            this.mouse?.tiledImage.setPaused(true);
            this.mouse?.tiledImage.tick(this.mouse.x, this.mouse.y);
        }
        if (this.gameState == 1) {
            this.mouse.tiledImage.setPaused(false);
            let isCollidingWithSideWall = false;
            let isCollidingWithFloor = false;
            let isCollidingWithCheese = false;
            let isCollidingWithSpike = false;
            let isCollidingWithJump = false;

            this.mazeDivs.forEach(mazeDiv => {
                if (mazeDiv.classList.contains('wall')) {
                    if (this.isColliding(this.mouse.div, mazeDiv, 0.2, 0.2)) {
                        isCollidingWithSideWall = true;
                    }
                    if (this.isColliding(this.mouse.div, mazeDiv, 0.45, 0)) {
                        isCollidingWithFloor = true;
                    }
                }
                else if (mazeDiv.classList.contains('spike')) {
                    if (this.isColliding(this.mouse.div, mazeDiv, 0.5, 0.5)) {
                        isCollidingWithSpike = true;
                    }
                }
                else if (mazeDiv.classList.contains('cheese')) {
                    if (this.isColliding(this.mouse.div, mazeDiv, 0.5, 0.5)) {
                        isCollidingWithCheese = true;
                    }
                }
                else if (mazeDiv.classList.contains('jump')) {
                    if (this.isColliding(this.mouse.div, mazeDiv, 0.5, 0.5)) {
                        isCollidingWithJump = true;
                    }
                }
            });

            if (isCollidingWithJump && this.mouse.y_speed >= 0) {
                this.mouse.y_speed = -275;
                this.mouse.y = this.mouse.y_previous;
                this.mouse.tiledImage.setPaused(true);
            }
            else if (!isCollidingWithFloor) {
                this.mouse.y_speed += this.gravity;
                this.mouse.tiledImage.setPaused(true);
            }
            else {
                if (this.mouse.y_speed < 0) {
                    this.mouse.y_speed = 0;
                    this.mouse.y = this.mouse.y_previous;
                }
                this.mouse.y_speed = 0;
                this.mouse.tiledImage.setPaused(false);
            }

            if (isCollidingWithSideWall) {
                this.mouse.x_speed = -this.mouse.x_speed;
                this.mouse.x = this.mouse.x_previous;
                this.mouse.y = this.mouse.y_previous;
                this.mouse.tiledImage.setFlipped(this.mouse.x_speed < 0);
            }

            this.mouse.x_previous = this.mouse.x;
            this.mouse.y_previous = this.mouse.y;
            this.mouse.x += (this.mouse.x_speed || 0) * delta;
            this.mouse.y += (this.mouse.y_speed || 0) * delta;
            this.mouse.tiledImage.tick(this.mouse.x, this.mouse.y);

            if (isCollidingWithCheese) {
                this.gameState = 2;
            }

            if (isCollidingWithSpike || this.mouse.y > this.gameSize) {
                this.gameState = 3;
            }
        }

        if (this.gameState == 2) {
            let winBtn = document.createElement('button');
            winBtn.classList.add('win');
            winBtn.innerHTML = "Vous avez gagné !";
            winBtn.onclick = () => window.location.href = 'index.html';
            this.levelContainer.appendChild(winBtn);
            isRunning = false;
        }
        else if (this.gameState == 3) {
            let loseBtn = document.createElement('button');
            loseBtn.classList.add('loose');
            loseBtn.innerHTML = "Vous avez perdu !";
            loseBtn.onclick = () => window.location.reload();
            this.levelContainer.appendChild(loseBtn);
            isRunning = false;
        }

        return isRunning;
    }
}
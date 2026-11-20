let messages = [];

document.querySelector("#chat-form").addEventListener("submit", async (e) => {
    e.preventDefault();
    const input = document.querySelector("#chat-form input");
    const message = input.value.trim();

    if (message) {
        addMessage("user", message);
        input.value = "";

        messages.push({
            content: message,
            role: "user",
        })

        fetch("http://localhost:8123/v1/chat/completions", {
            method: "POST",
            headers: { 'Content-Type': 'text/plain' },
            body: JSON.stringify({messages : messages}),
        })
        .then(response => response.json())
        .then(data => {
            let msg = data.choices[0].message;
            addMessage("assistant", msg.content);
            messages.push(msg);
        })
        .catch(error => {
            console.error("Error:", error);
            addMessage("assistant", "Désolé, une erreur est survenue, je ne crois pas être démarré ou disponible. 😞", true);
        });
    }
});

const addMessage = (sender, text, isError = false) => {
    const chatBox = document.querySelector("#chat-box");
    const lineElem = document.createElement("div");
    lineElem.classList.add("line", sender);
    const messageElem = document.createElement("div");
    messageElem.classList.add("message");
    messageElem.textContent = text.trim();

    if (isError) {
        messageElem.style.color = "red";
    }

    chatBox.appendChild(lineElem);
    lineElem.appendChild(messageElem);
    chatBox.scrollTop = chatBox.scrollHeight;
};

window.addEventListener("DOMContentLoaded", () => {
    addMessage("assistant", "Bonjour ! Comment puis-je vous aider aujourd'hui ?");
});
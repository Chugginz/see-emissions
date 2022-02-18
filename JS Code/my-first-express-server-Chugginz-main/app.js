'use strict';

const express = require("express");
const app = express();

const groceryList = {};

app.get("/", (request, response) => {
    response.send("Christian Huggins");
});

app.get("/api/groceryList", (request, response) => {
    response.json(groceryList);
});

app.post("/api/groceryList", (request, response) => {
    const item = request.body.item;
    const quantity = request.body.quantity;

    if (item === "" || isNaN(quantity) || quantity <= 0)
        response.sendStatus(400);

    if (!groceryList[item])
        groceryList[item] = quantity;
    else
        groceryList[item] += quantity;

    response.json(groceryList);
});

app.get("/api/groceryList/:item", (request, response) => {

    // If the grocery list item 
    if (!groceryList[request.params.item])
        response.sendStatus(404);

    response.json(groceryList[request.params.item]);
});

module.exports = app;
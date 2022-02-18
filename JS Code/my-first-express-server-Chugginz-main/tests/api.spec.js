const fs = require('fs/promises');
const request = require('supertest');
const app = require("../app");

describe('Server exists', () => {
    it('server.js exists', async () => {
        const f = await fs.stat("server.js");
    });
    
    it('app.js exists', async () => {
        const f = await fs.stat("app.js");
    });
});

describe("Test the root path", () => {
    test("It should respond with your name", async () => {
      const response = await request(app).get("/");
      expect(response.statusCode).toBe(200);
      expect(response.text).toEqual(expect.stringMatching(/[A-Z][a-z]+ [A-Z][a-z]+/))
    });
});

describe("Test the API", () => {
    test("GET /api/groceryList: Empty list", async () => {
        const response = await request(app)
            .get("/api/groceryList");
        expect(response.body).toStrictEqual({});
    });

    test("POST /api/groceryList: Adding 1 milk", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: 'milk', quantity: 1});

        expect(response.body).toStrictEqual({'milk': 1});
    });

    test("POST /api/groceryList: Adding empty item name", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: '', quantity: 10});

        expect(response.statusCode).toBe(400);
    });

    test("POST /api/groceryList: Adding Non numeric quantity", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: 'milk', quantity: "hi"});

        expect(response.statusCode).toBe(400);
    });

    test("POST /api/groceryList: Adding Zero quantity", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: 'milk', quantity: 0});

        expect(response.statusCode).toBe(400);
    });

    test("POST /api/groceryList: Adding negative quantity", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: 'milk', quantity: -10});

        expect(response.statusCode).toBe(400);
    });
    
    test("POST /api/groceryList: Adding 2 water", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: 'water', quantity: 2});

        expect(response.body).toStrictEqual({'milk': 1, 'water': 2});
    });

    test("POST /api/groceryList: Adding 4 more milk", async () => {
        const response = await request(app)
            .post("/api/groceryList")
            .send({item: 'milk', quantity: 4});

        expect(response.body).toStrictEqual({'milk': 5, 'water': 2});
    });

    test("GET /api/groceryList: Getting the list", async () => {
        const response = await request(app)
            .get("/api/groceryList")

        expect(response.body).toStrictEqual({'milk': 5, 'water': 2});
    });

    test("GET /api/groceryList/milk: Getting milk", async () => {
        const response = await request(app)
            .get("/api/groceryList/milk")

        expect(response.body).toStrictEqual({item: 'milk', quantity: 5});
    });

    test("GET /api/groceryList/water: Getting water", async () => {
        const response = await request(app)
            .get("/api/groceryList/water")

        expect(response.body).toStrictEqual({item: 'water', quantity: 2});
    });

    test("GET /api/groceryList/bread: Getting bread (does not exist)", async () => {
        const response = await request(app)
            .get("/api/groceryList/bread")

        expect(response.statusCode).toBe(404);
    });
});

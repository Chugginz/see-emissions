[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6858666&assignment_repo_type=AssignmentRepo)
# My First Express Server

Before you do anything make sure you run `npm install` so you can install the test dependencies. You will need to explicitly install express.

Remember to add `"use strict";` at the start of your JavaScript files. Also recall that you need to set your app to parse a JSON encoded message body.

## Automated Tests

In the first class example we put all of our application login inside of `index.js`. This is fine for a simple example; however, it becomes unmanageable as the application becomes more complex. For this assignment we'll add more organization to the project.

First, is the `server.js`/`app.js` split and the lack of `index.js`. `index.js` is just the default name for a node project's entry point (i.e. the file you execute) and you can call it whatever you want. We will change it to the more semantic `server.js`. Since we want this to be the new entry point for our project you need to update the `main` field in `package.json`. I've already updated the name for this template but you should still open `package.json` and familiarize yourself with it.

You may be wondering "Why not just put everything inside `server.js`?" especially since this assignment only has you creating 4 endpoints. Why add the complexity for such a simple program? This is to facilitate automated testing. 

### Testing with `jest`

I have set up tests using two frameworks called *Jest* and *Supertest* to implement the automated test suite. You can open the `/tests` folder and look at the `api.spec.js` file.

To test your code you need to be able to turn on the server and make HTTP requests and then verify that the HTTP Response is correct. However, the test code needs to be able to control when the server turns on, what port is listens on, and when to turn off the server. To simplify this we will create a file called `app.js` which contains our code that sets up the application server but **does not** call the `.listen()` method.

Then in `server.js` we will import the `app` object using `require()` and then call the `.listen()` method. This allows us to separate the implementation of the application (`app.js`) from the when we bind the app to a port (`server.js`). Now we can simply import the `app` object in other files and spawn multiple servers! We will use this to create a server for development **and** a server for automated tests.

Now you need to actually create `server.js` and `app.js`

## `app.js`

This file will contain your route handlers and application object. It will be very similar to the example `index.js` from class; however, you **should not** call `.listen()` in this file. This file is only responsible for creating the application object and not initializing the server.

Your server must support 4 endpoints:

- `GET  /`
- `GET  /api/groceryList`
- `POST /api/groceryList`
- `GET  /api/groceryList/:item`

This API will allow adding to and reading from an in-memory grocery list. To implement this you should create a global constant called `groceryList` and initialize it to an empty object.

### `GET /`

This endpoint will simply respond with the message body containing a string of your first and last name.

Use the `Response` object's `.send()` method to send plaintext.

### `GET /api/groceryList`

This endpoint will simply respond with the `groceryList`.

Use the `Response` object's `.json()` method to send a JSON response body.

### `POST /api/groceryList`

This endpoint will add an item and quantity to the `groceryList`. The request body must be a JSON encoded object containing the properties `item` and `quantity`.

Use the `Request` object's `.body` property to access the message body.

You must perform input validation. The input validation rules are:
- if the `item` is an empty string (you can use the not operator `!`)
- if `quantity` is not a number (use `isNaN()` [read the docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/isNaN))
- if `quantity` is not positive
  
Then you must respond with status `400 Bad Request`.

If the item is already in the grocery list then you must add the quantity to the current amount. Otherwise add the item with the supplied quantity. Then send back the updated `groceryList` in the response. For example if the following three request bodies were sent:

```json
{"item": "milk", "quantity": 1}
{"item": "water", "quantity": 4}
{"item": "milk", "quantity": 2}
```

Then the grocery list should now contain:

```json
{"milk": 3, "water": 4}
```

Use the `Response` object's `.json()` method to send a JSON response body.

### `GET /api/groceryList/:item`

The path in this endpoint contains `:item`. This type of path segment referred to as a named segment. These are called "route parameters" in the express [documentation](https://expressjs.com/en/guide/routing.html). Check the docs for the proper syntax for named segments. 

You can access the route parameters using the `req.params` property. For this particular endpoint you would use `req.params.item`.

This endpoint will check if the `item` supplied in the path parameter is in the grocery list. If so it should respond with a JSON encoded object containing the `item` and `quantity` using [`res.json()`](https://expressjs.com/en/api.html#res.json). If the `item` is not in the grocery list then it should respond with status `404 Not Found` using [`res.sendStatus()`](https://expressjs.com/en/api.html#res.sendStatus)

### Exporting the `app`

Now that you have implemented all 4 endpoints you can export the `app` object. Add the following line to the very end of `app.js`. It must be the last line in the file.

```js
module.exports = app;
```

In C/C++ or Python you can `#include` or `import` from any file. However in JavaScript, you must explicitly export something so that you can import (i.e. `require()`) it in another file.

## `server.js`

Now that you have completed `app.js` you can implement `server.js`. You only need 3 things in this file:

1. `"use strict";` directive (always put this in your JS files)
2. `require()` the app
3. Call `.listen()`

```js
"use strict";

// Notice that I include ./ which tells JS to find the app.js file in the
// current directory. Also you should omit the .js extension from the filename
const app = require("./app");

// YOUR CODE HERE: Now listen on port 3000
```

### Testing

You can run the tests using `npm run test`.
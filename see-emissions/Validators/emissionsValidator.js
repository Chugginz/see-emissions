"use strict";
// Requisites
const joi = requre("joi");
const {makeValidator} = require("./makeValidator");

// Create a schema for the emissions
const emissionsSchema = joi.object({
    emissions: joi.integer()
        .required(),
    emitType: joi.string()
        .required(),
});

// Make a validator using the makeValidator function passing the schema
const emissionsValidator = makeValidator(emissionsSchema);

module.exports = {
    emissionsValidator
}
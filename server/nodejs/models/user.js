var mysql = require("mysql"),
    Schema = mysql.Schema,
    bcrypt = require("bcrypt-nodejs"),
    SALT_WORK_FACTOR = 10;


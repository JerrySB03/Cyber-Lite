CREATE TABLE Users (
    id INTEGER PRIMARY KEY,
    username VARCHAR VARCHAR(127) UNIQUE NOT NULL,
    email VARCHAR VARCHAR(255) UNIQUE NOT NULL,
    hash VARCHAR,
    salt VARCHAR,
    token VARCHAR,
    config VARCHAR,
    token_expiration TIMESTAMP,
    last_test TIMESTAMP
);
INSERT INTO Users (username, email, hash, salt)
VALUES (
        'test',
        'example@example.com',
        "FC765501AB50CFA8FD60BE73BD8F0F0F4AB8CFC9BECF1DFA61C62A52CAE25E6ABADE37B040578AE14B8566BB328839D6C98F1E76A1F01DA34A9B9E22BDE17B53",
        "0000000000000000000000000000000000000000000000000000000000000000"
    );
--Password is 'test'
CREATE TABLE Tasks (
    id INTEGER PRIMARY KEY,
    name VARCHAR UNIQUE NOT NULL,
    description VARCHAR,
    content VARCHAR,
    categories VARCHAR
);
CREATE TABLE Questions(
    task_id INTEGER PRIMARY KEY,
    name VARCHAR 
    questions VARCHAR,
    content VARCHAR,
    categories VARCHAR
);

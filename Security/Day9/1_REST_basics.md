REST API stands for Representational State Transfer API. REST API stands for Representational State Transfer API. 
![alt text](image.png)

A request is sent from the client to the server via a web URL, using one of the HTTP methods.
The server then responds with the requested resource, which could be HTML, XML, Image, or JSON, with JSON being the most commonly used format for modern web services.
These methods map to CRUD operations (Create, Read, Update, Delete) for managing resources on the web.

NOTE: REST is an architectural design style for APIs, while HTTP is the communication protocol used for data transfer over the web. REST APIs use HTTP methods to interact with resources, but they are not the same thing. REST defines how the APIs should behave, while HTTP defines the rules for communication over the web. They commonly work together, but they serve different purposes


Common HTTP Methods Used in REST API
In HTTP, there are five methods that are commonly used in a REST-based Architecture, i.e., POST, GET, PUT, PATCH, and DELETE. These correspond to create, read, update, and delete (or CRUD) operations, respectively. There are other methods that are less frequently used, like OPTIONS and HEAD.

1. GET Method:

The HTTP GET method is used to read (or retrieve) a representation of a resource. In the safe path, GET returns a representation in XML or JSON and an HTTP response code of 200 (OK). In an error case, it most often returns a 404 (NOT FOUND) or 400 (BAD REQUEST).

GET /users/123
This request fetches data for the user with ID 123.

2. POST Method
The POST method is commonly used to create new resources. It is often used to create subordinate resources related to a parent resource. Upon successful creation, the server returns HTTP status 201 (Created) along with a Location header pointing to the newly created resource.

POST /users
{ 
  "name": "Anjali", 
  "email": "gfg@example.com"
}

This request creates a new user with the given data.

NOTE:  POST is neither safe nor idempotent meaning that multiple identical POST requests will create multiple resources.

3. PUT Method
PUT is an HTTP method used to update or create a resource on the server. When using PUT, the entire resource is sent in the request body, and it replaces the current resource at the specified URL. If the resource doesn’t exist, it can create a new one.

PUT /users/123
{ 
  "name": "Anjali", 
  "email": "gfg@example.com"
}
This request updates the user with ID 123 with the provided data. If the user does not exist, it creates a new user with that ID.

4. PATCH Method
PATCH is an HTTP method used to partially update a resource on the server. Unlike PUT, PATCH only requires the fields that need to be updated to be sent in the request body. It modifies specific parts of the resource rather than replacing the entire resource.

PATCH /users/123
{ 
  "email": "new.email@example.com" 
}
This request updates only the email of the user with ID 123, leaving the rest of the user data unchanged.

Differences Between PUT & PATCH
Both PATCH and PUT are used to update resources on the server, but they differ in how they handle the update process:

PUT	                                            PATCH
Replaces the entire resource	                Updates only specified fields
Must send full data	                            Only sends changes
Idempotent	                                    Not always idempotent
Example: Updating a user’s entire profile	    Example: Changing just a user’s email


5. DELETE Method
It is used to delete a resource identified by a URI. On successful deletion, return HTTP status 200 (OK) along with a response body.

DELETE /users/123
This request deletes the user with ID 123.

Idempotence: An idempotent HTTP method is a HTTP method that can be called many times without different outcomes. It would not matter if the method is called only once, or ten times over. The result should be the same. Again, this only applies to the result, not the resource itself.
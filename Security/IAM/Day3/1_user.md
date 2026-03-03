What is a User?
User accounts are created and stored as objects in Active Directory Domain Services. User accounts can be used by human users or programs such as system services use to log on to a computer. When a user logs on, the system verifies the user's password by comparing it with data stored in the user's user object in the Active Directory server. If the password is authenticated, that is, the password presented matches the password stored in the user object, the system produces an access token. An access token is an object that describes the security context of a process or thread. The data in a token includes the security identity and group memberships of the user account associated with the process or thread. Every process executed on behalf of this user has a copy of this access token. The access token is used by the system to determine whether the process or thread has permission to access a securable object. A user account can be assigned permissions to access securable objects, and these permissions are stored in the access token. When a process or thread attempts to access a securable object, the system checks the permissions in the access token against the permissions required to access the object. If the permissions match, the system allows access; otherwise, it denies access.

A user account can be used to:
* Enable human users to log on to a computer and to access resources based on that user account's identity.
* Enable programs and services to run under a specific security context.
* Manage user access to shared resources such as objects and their properties, network shares, files, directories, printer queues, and so on.

Groups can contain members, which are references to users and other groups. Groups can also be used to control access to shared resources. When assigning permissions for resources, for example file shares, printers, and so on, administrators should assign those permissions to a group rather than to the individual users. The permissions are assigned once to the group, instead of several times to each individual user. This helps simplify the maintenance and administration of a network.

* Users compared to Contacts :-

Both users and contacts can be used to represent human users. However, a user is a security principal; a contact is not.
A user can be used to enable a human user to log on and access shared resources.
A contact is used only for distribution list and email purposes. However, a contact can contain most of the data stored in a user object such as address, phone numbers, and so on because both user and contact are derived from the person classSchema object. A contact has no security context; therefore, a contact cannot be used to control access to shared resources and cannot be used to log on to a computer.

* Users compared to Computers :-

The computer object class inherits from the user object class. A computer object represents a computer; however, the computer and the computer's local services often require access to the network and shared resources. When the computer accesses shared resources, not the user logged on to the computer, it needs an access token just as a human user logged on as a user does. When a computer accesses the network, it uses an access token that contains the security identifier for the computer's computer account and the groups that account is a member.

# What is IAM user?
An IAM User, short for Identity and Access Management User, is a digital identity representing a person or application that interacts with cloud resources. It’s a fundamental concept in cloud security, ensuring that only authorized entities can access specific services and data. The core function of an IAM user is authentication and authorization. Authentication verifies the user’s identity (proving they are who they claim to be), while authorization determines what actions they are permitted to perform. IAM users are created and managed within an IAM system, which allows administrators to define permissions and access levels for each user. This can include granting access to specific resources, defining roles, and setting policies that govern how users can interact with the cloud environment. By using IAM users, organizations can maintain a secure and organized approach to managing access to their cloud resources, ensuring that only the right people or applications have the necessary permissions to perform their tasks.

# IAM User Examples:

Consider a scenario where a software developer needs to deploy a new application to a cloud platform. Instead of granting them full administrative privileges (which would be a significant security risk), an IAM user is created for them with specific permissions. These permissions might include the ability to launch virtual machines, upload code, and configure network settings, but explicitly exclude the ability to access sensitive databases or modify security policies. This principle of least privilege ensures that the developer can perform their necessary tasks without unnecessarily exposing the cloud environment to potential threats. You might see a user needing help to see resources they created. IAM users are also critical for managing access for automated processes and applications. For instance, a backup script running on a server might need to access storage services to upload daily backups. An IAM user can be created specifically for this script, granting it only the permissions required to read and write to the designated backup storage location.

Human vs Non-Human IAM Users

IAM users can represent both human users (individuals with usernames and passwords) and non-human entities (applications, services, or devices). Human users typically interact with cloud resources through a console, command-line interface, or application, while non-human users typically access resources programmatically using API keys or access tokens. Managing non-human identities can present unique challenges.

# Granular Access Control

IAM enables granular access control, allowing administrators to define fine-grained permissions for each user. This is achieved through the use of policies, which are documents that define what actions a user is allowed or denied to perform on specific resources. For example, a policy might grant a user read-only access to a particular database table or allow them to create new virtual machines in a specific region. This level of control is crucial for maintaining a secure and compliant cloud environment. Policies are essential for robust identity and access management.

# Benefits of IAM Users

Enhanced Security: IAM enforces the principle of least privilege, minimizing the potential attack surface and reducing the risk of unauthorized access.
Simplified Compliance: By providing granular access control and audit trails, IAM helps organizations meet regulatory requirements and demonstrate compliance.
Centralized Management: IAM provides a central point for managing user identities and permissions, simplifying administration and improving visibility.
Scalability: IAM can scale to accommodate the needs of growing organizations, supporting a large number of users and resources.
Cost Optimization: By limiting access to only the necessary resources, IAM helps organizations optimize cloud spending and avoid unnecessary costs.
Improved Productivity: IAM streamlines access management, allowing users to quickly and easily access the resources they need to perform their jobs.

# IAM User Authentication Methods :

IAM users can be authenticated using various methods, including passwords, multi-factor authentication (MFA), and API keys. Passwords are the most basic form of authentication, but they are also the most vulnerable to compromise. MFA adds an extra layer of security by requiring users to provide a second form of verification, such as a code from a mobile app or a hardware token. API keys are used for programmatic access to cloud resources and should be carefully protected. It is important to manage these secrets securely.

## Role-Based Access Control (RBAC):
IAM often incorporates Role-Based Access Control (RBAC), which simplifies user management by assigning permissions based on roles rather than individual users. A role is a collection of permissions that define what actions a user can perform. Users are then assigned to one or more roles, inheriting the permissions associated with those roles. This approach makes it easier to manage permissions for large groups of users and ensures consistency across the organization. RBAC is a core component of many IAM systems.


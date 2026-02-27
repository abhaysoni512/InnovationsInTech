Privileged User Auditing in Linux monitors actions by users with elevated privileges, such as root or those using sudo/su, to ensure security and compliance. It typically leverages the auditd daemon to log system calls, file accesses, and commands executed under privilege escalation. This helps detect unauthorized activities and maintain audit trails

Core Purpose

    The primary goal is to track administrative actions, like command executions or configuration changes, by privileged accounts. Tools like auditd create rules to capture events from sudo usage or root sessions, preventing misuse while providing forensic data. Logs include details such as user ID, timestamps, and executed commands.

Setup with Auditd

    install auditd via package manager (e.g., apt install auditd on Ubuntu or yum install auditd on RHEL), then configure rules in /etc/audit/rules.d/audit.rules.
    Key rules include -a always,exit -F arch=b64 -S execve -F auid>=1000 -F auid!=unset -k privileged for privileged commands and -w /etc/sudoers -p wa -k sudoers_change for sudo file watches.
    Reload rules with augenrules --load and restart the service.

    Configuring Rules :

    Edit /etc/audit/rules.d/audit.rules to add persistent rules targeting privileged actions. Essential rules for privileged auditing include:

        * -a always,exit -F arch=b64 -S execve -F auid>=1000 -F auid!=unset -F euid=0 -k privileged (logs commands run as root by non-initial users).

        * -w /etc/sudoers -p wa -k sudoers_change (watches sudoers file changes).

        * -a always,exit -F arch=b64 -S execve -F path=/usr/bin/sudo -F perm=x -F auid>=1000 -F auid!=unset -k sudo (tracks sudo executions).
        Use 32-bit equivalents (arch=b32) if needed for multi-arch systems. Assign keys like "privileged" or "sudo_log" for easy log filtering

    Loading and Applying :

        Merge rules with sudo augenrules --load (or sudo auditctl -R /etc/audit/rules.d/audit.rules), 
        then restart the service: sudo systemctl restart auditd. 
        List active rules via sudo auditctl -l to confirm. 
        Test by running sudo ls and check logs with sudo ausearch -k privileged.
​
****************************************************************************************************

ausearch : 

The ausearch utility allows you to search Audit log files for specific events. By default, ausearch searches the /var/log/audit/audit.log file. You can specify a different file using the ausearch options -if file_name command. Supplying multiple options in one ausearch command is equivalent to using the AND operator between field types and the OR operator between multiple instances of the same field type

Using ausearch to Search Audit Log Files

To search the /var/log/audit/audit.log file for failed login attempts, use the following command:

    ausearch --message USER_LOGIN --success no --interpret

To search for all account, group, and role changes, use the following command:

    ausearch --message USER_ACCT --message USER_GROUP --message USER_ROLE --interpret

To search for all logged actions performed by a certain user, using the user's login ID (auid), use the following command:

    ausearch --auid 1001 --interpret

To search for all failed system calls from yesterday up until now, use the following command:
    ausearch --start yesterday --success no --interpret
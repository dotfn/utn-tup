FROM eclipse-temurin:21-jdk

# Variables para usuario
ARG USERNAME=default
ARG USER_UID=1000
ARG USER_GID=1000

# Borrar usuario/grupo previos (si existen) y crear nuevos
RUN if getent passwd $USER_UID >/dev/null; then \
        olduser=$(getent passwd $USER_UID | cut -d: -f1); \
        userdel -r $olduser || true; \
    fi && \
    if getent group $USER_GID >/dev/null; then \
        oldgroup=$(getent group $USER_GID | cut -d: -f1); \
        groupdel $oldgroup || true; \
    fi && \
    groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

# Crear directorio del proyecto y asignar permisos
RUN mkdir -p /home/$USERNAME/src && \
    chown -R $USERNAME:$USERNAME /home/$USERNAME/src

# Cambiar a usuario no-root
USER $USERNAME
WORKDIR /home/$USERNAME/src

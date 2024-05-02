// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'AppStore.dart';

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic, no_leading_underscores_for_local_identifiers

mixin _$AppStore on _AppStore, Store {
  late final _$isLoggedInAtom =
      Atom(name: '_AppStore.isLoggedIn', context: context);

  @override
  bool get isLoggedIn {
    _$isLoggedInAtom.reportRead();
    return super.isLoggedIn;
  }

  @override
  set isLoggedIn(bool value) {
    _$isLoggedInAtom.reportWrite(value, super.isLoggedIn, () {
      super.isLoggedIn = value;
    });
  }

  late final _$isAdminLoggedInAtom =
      Atom(name: '_AppStore.isAdminLoggedIn', context: context);

  @override
  bool get isAdminLoggedIn {
    _$isAdminLoggedInAtom.reportRead();
    return super.isAdminLoggedIn;
  }

  @override
  set isAdminLoggedIn(bool value) {
    _$isAdminLoggedInAtom.reportWrite(value, super.isAdminLoggedIn, () {
      super.isAdminLoggedIn = value;
    });
  }

  late final _$isLoadingAtom =
      Atom(name: '_AppStore.isLoading', context: context);

  @override
  bool get isLoading {
    _$isLoadingAtom.reportRead();
    return super.isLoading;
  }

  @override
  set isLoading(bool value) {
    _$isLoadingAtom.reportWrite(value, super.isLoading, () {
      super.isLoading = value;
    });
  }

  late final _$selectedMenuIndexAtom =
      Atom(name: '_AppStore.selectedMenuIndex', context: context);

  @override
  int get selectedMenuIndex {
    _$selectedMenuIndexAtom.reportRead();
    return super.selectedMenuIndex;
  }

  @override
  set selectedMenuIndex(int value) {
    _$selectedMenuIndexAtom.reportWrite(value, super.selectedMenuIndex, () {
      super.selectedMenuIndex = value;
    });
  }

  late final _$isMenuExpandedAtom =
      Atom(name: '_AppStore.isMenuExpanded', context: context);

  @override
  bool get isMenuExpanded {
    _$isMenuExpandedAtom.reportRead();
    return super.isMenuExpanded;
  }

  @override
  set isMenuExpanded(bool value) {
    _$isMenuExpandedAtom.reportWrite(value, super.isMenuExpanded, () {
      super.isMenuExpanded = value;
    });
  }

  late final _$setLoggedInAsyncAction =
      AsyncAction('_AppStore.setLoggedIn', context: context);

  @override
  Future<void> setLoggedIn(bool val, {bool isInitializing = false}) {
    return _$setLoggedInAsyncAction
        .run(() => super.setLoggedIn(val, isInitializing: isInitializing));
  }

  late final _$setAdminLoggedInAsyncAction =
      AsyncAction('_AppStore.setAdminLoggedIn', context: context);

  @override
  Future<void> setAdminLoggedIn(bool val, {bool isInitializing = false}) {
    return _$setAdminLoggedInAsyncAction
        .run(() => super.setAdminLoggedIn(val, isInitializing: isInitializing));
  }

  late final _$setLoadingAsyncAction =
      AsyncAction('_AppStore.setLoading', context: context);

  @override
  Future<void> setLoading(bool value) {
    return _$setLoadingAsyncAction.run(() => super.setLoading(value));
  }

  late final _$_AppStoreActionController =
      ActionController(name: '_AppStore', context: context);

  @override
  void setSelectedMenuIndex(int val) {
    final _$actionInfo = _$_AppStoreActionController.startAction(
        name: '_AppStore.setSelectedMenuIndex');
    try {
      return super.setSelectedMenuIndex(val);
    } finally {
      _$_AppStoreActionController.endAction(_$actionInfo);
    }
  }

  @override
  void setExpandedMenu(bool val) {
    final _$actionInfo = _$_AppStoreActionController.startAction(
        name: '_AppStore.setExpandedMenu');
    try {
      return super.setExpandedMenu(val);
    } finally {
      _$_AppStoreActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
isLoggedIn: ${isLoggedIn},
isAdminLoggedIn: ${isAdminLoggedIn},
isLoading: ${isLoading},
selectedMenuIndex: ${selectedMenuIndex},
isMenuExpanded: ${isMenuExpanded}
    ''';
  }
}
